#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,f=0,c=0;
	cin>>n;
	int a[25555555555]={};
	string b[25555555555]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		f+=a[i];
	}
	if(f%2==1){
		f-=1;
	}
	f/=2;
	for(int i=1;i<=f;i++){
		int d=1,e;
		for(int j=1;j<=n;j++){
			e+=a[d];
			if(e<f){
				d++;
			}
		}
		if(b[d]!=b[n-d]){
			c++;
		}
	}
	cout<<c;
}
