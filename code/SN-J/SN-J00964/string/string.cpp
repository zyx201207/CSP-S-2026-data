#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r"stdin);
freopen("string.out","w",stdout);	
    int n,k=1,f=1;
	cin>>n;
	int a[n];
	int bb[1001]={0};
	for(int i=1;i<=n;i++)
		int b;
		char a1;
		cin>>b>>a1;
		for(int j=1;j<=b;j++){
			a[j]=a1;
		}		   
	for(int j=b;j>=1;i--){
		a[j]=bb[j];
		if(bb[k]!=bb[j]){
			f+=1;
			k+=1;	
		}
	}
	 if(a[i]==bb[i]){
	 	cout<<"0";
	 }else{
	 cout<<f;
	 }
	return 0;
}
