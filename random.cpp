
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,r;
	cout<<"Enter a Number\n";
	cin>>a;
	for(int i=0;i<a;i++){
	r=(rand()*2+rand())%99;
	if(r<0)
        r=r*-1;
	cout<<r<<" ";	
	}
 return 0;	
}
