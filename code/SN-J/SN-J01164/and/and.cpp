#include<bits/stdc++.h>
using namespace std;
int n,m,maxa;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	maxa=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			}
		}
		cout<<maxa;
		return 0;
	}
	if(m==n){
		maxa=a[1];
		for(int i=1;i<=n;i++){
			maxa&=a[i];
		}
		cout<<maxa;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int ans=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans&=a[j];
				}
			}
			maxa=max(maxa,ans);
		}
		cout<<maxa;
		return 0;
	}
	return 0;
} 
