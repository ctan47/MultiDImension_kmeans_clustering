#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std; 
struct verify{
	int idx;
	bool chk;
};
int main(){
    string filename;
    cout<<"Enter filename:";
    cin>>filename;
    int i=0,j,K,k,n,size,idx=0;
	float element,diff,dist;
	bool z=true;   
    vector<float> arr; 
    ifstream mFile (filename);  
    if(mFile.is_open())
    {
        while(!mFile.eof())
        {
            mFile>>element;
            arr.emplace_back(element);
            
            
        }
        mFile.close();
    }
    else {
    	cout<<"Unable to open the file"<<endl;
	    return 0;
	}
    cout<<endl<<" File has this Elements:"<<endl;
	for(i=0;i<arr.size();i++){
    	cout<<arr[i]<<",";
	}
    
    cout<<endl<<"Enter No.Of classes you want to divide the data  in:";
    cin>>k;
    K=k*n;
    cout<<endl<<"Enter the no. of Dimension: ";
    cin>>n;
    float copy[k][n],sum[n];
    vector<float> Classes[k];
    size=arr.size();
    for(i=0;i<k;i++){
    	for(int j=0;j<n;j++){
		
    	Classes[i].emplace_back(arr[n*i+j]);
    	copy[i][j]=arr[n*i+j];
        }
	}
	verify A[size/n];
	for(i=0;i<size/n;i++){
		A[i].chk=false;
		A[i].idx=-2;
	}
	while(z){
		for(i=0;i<arr.size();i+=n){
			idx=0;
			dist=0;
			//for(j=0;j<k;j++){
			for(int x=0;x<n;x++){
			    dist=dist +fabs((Classes[0][x]-arr[i+x])*(Classes[0][x]-arr[i+x]));
			}
			dist=sqrt(dist);
		   
			for(j=1;j<k;j++){
				diff=0;
				for(int x=0;x<n;x++){
			    diff=diff+fabs((Classes[j][x]-arr[i+x])*(Classes[j][x]-arr[i+x]));
			    }
			   diff=sqrt(diff);
				if(dist>diff){
				dist=diff;
				idx=j;
				}
			}
			if(A[i/n].idx==idx){
				A[i/n].chk=true;
			}
			A[i/n].idx=idx;
			for(int x=0;x<n;x++){
	            Classes[idx].emplace_back(arr[i+x]);		
			}
		}
			for(i=0;i<k;i++){
				for(int x=n;x<2*n;x++){
				sum[x-n]=0;
				for(j=x;j<Classes[i].size();j+=n){
					sum[x-n]=sum[x-n]+Classes[i][j];
				}
			   }
				if(Classes[i].size()==n)
				   {
				   for(j=0;j<n;j++)
				   copy[i][j]=Classes[i][j];}
				else{
				
				for(j=0;j<n;j++)
				   copy[i][j]=sum[j]/((Classes[i].size()/n)-1);
			    }
			}
			z=false;
			for(i=0;i<size/n;i++){
				
				if(A[i].chk==false){
					z=true;
				    break;
			    }
		    }
			if(z){
				for(i=0;i<k;i++){
					Classes[i].clear();
					for(j=0;j<n;j++)
					Classes[i].emplace_back(copy[i][j]);
				}
			}
	}
	for(i=0;i<k;i++){
		cout<<endl<<i+1<<")"<<"->"<<endl;
		for(j=0;j<Classes[i].size();j++){
			if(j%n==0)
			cout<<"{";
			cout<<" "<<Classes[i][j];
			if((j+1)%n==0)
			cout<<"}";
			else
			cout<<",";
			
            }
        
        cout<<endl;
    }

    cout<<endl<<"Ended with the Task!";
    cout<<"\n Enter filename for output:";
    cin>>filename;
	ofstream nFile (filename);  
    if(nFile.is_open()){ 
	    i=0;
        cout<<"\n Data writing in file ";
        while(i<k){
            nFile<<i+1<<"->\n";
            for(j=0;j<Classes[i].size();j++){
            	if(j%n==0)
			nFile<<"{";
                nFile<<" "<<Classes[i][j];
                if((j+1)%n==0)
			nFile<<"}";
			else
			nFile<<",";
               
            }   
            i++;
        }
        cout<<"\n data writing successful";
	    nFile.close();
    }      
    return 0;
}
   