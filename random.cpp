
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cout<<"Enter a Number\n";
	cin>>a;
	for(int i=0;i<a;i++)
	cout<<" "<<(rand()*2+rand())%99;
	
 return 0;	
}