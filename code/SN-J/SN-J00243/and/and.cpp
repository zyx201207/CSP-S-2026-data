#include<bits/stdc++.h>
using namespace std;

int ans;

void solve(int n,int m){
	int vis[n];
	int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
		vis[i]=0;
	}
	ans=a[0];
	for(int i=1;i<n;++i){
		ans=ans&a[i];
	}
	int s=ans,x=0;
	if(m==n) return;
	ans=0;
	while(m<=n){
		for(int i=0;i<n;++i){
			if(vis[i]==1) continue;
			if(s&a[i]>=ans){
				ans=s&a[i];
				s=ans;
				x=i;
			}
		}
		vis[x]=1;
		m++;
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	solve(n,m);
	cout<<ans;
	return 0;
}
