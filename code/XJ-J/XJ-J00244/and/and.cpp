#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans,mx=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		mx=0;
		for(int j=1;j<=n;j++){
			if(a[j]>mx){
				mx=a[j];
				a[j]=0;
			}
		}
		if(i==1){
			ans=mx;
		}else{
			ans&=mx;
		}
	}
	cout<<ans;
} 
