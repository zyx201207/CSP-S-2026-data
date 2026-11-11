#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,p,m=0;
	string a,b;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++){
		for(int j=1;j<=p-i;j++){
			if(a[i]==j){
				n=i;
				for(int c=n;c>i+1;c--){
					a[c]=' ';
				}
			}else{
				a[n]=j;
				n++;	
			}
		}
		cout<<a[n]<<" ";
	}
}