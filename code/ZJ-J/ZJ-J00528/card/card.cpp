#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500025];
int ans[300025]; 
int vis[300025];
int chr[500025];
vector<pair<int,int> > e[500025];
void dfs(int u){
	chr[u]=1;
	for(auto p:e[u]){
		int v=p.first;
		int w=p.second;
		dfs(v);
		chr[u]+=chr[v];
		ans[w]+=chr[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		int v=vis[a[i]];
		if(v) e[v].push_back({i,0});
		else e[i+1].push_back({i,a[i]});
		vis[a[i]]=i;
	}dfs(n+1);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
