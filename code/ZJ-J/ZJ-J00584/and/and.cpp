#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mx,n,m,a[200010];
int vis[200010];

ll dfs(ll len,ll ss){
	if(len>=m){
		mx=max(ss,mx);
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]==1)	continue;
		vis[i]=1;
		dfs(len+1,(ss & a[i]));
		vis[i]=0;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<mx;
	return 0;
}