#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[222222];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mn=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=max(mn,a[i]);
	}
	if(m==1){
		cout<<mn;
		return 0;
	}
	if(m==n){
		int ans=0,s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}