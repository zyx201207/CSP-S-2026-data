#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int dp[N];
int fa[N][21],dep[N];
int n,k;
vector<int>g[N];
void dfs(int u,int f){
	fa[u][0]=f;dep[u]=dep[f]+1;
	for(int i=1;i<21;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int i=20;
	while(dep[a]>dep[b]){
		if(dep[fa[a][i]]>=dep[b])a=fa[a][i];
		i--;
	}
	for(int i=20;i>=0;i--)
		if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int dis(int a,int b){
	int l=lca(a,b);
	return dep[a]+dep[b]-2*dep[l];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);g[v].push_back(u);
		}
		cout<<(n-k)/3<<"\n";
	}
	return 0;
}