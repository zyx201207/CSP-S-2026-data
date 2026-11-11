#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1e9+7;
int n,m,dep[N],c,rt,fa[N];
vector<int>g[N];
void dfs(int u,int fath){
	dep[u]=dep[fath]+1;
	for(auto v:g[u]){
		if(v==fath)continue;
		dfs(v,u);
		if(dep[v]>dep[c])c=v;
	}
}
void dfs1(int u,int fath){
	dep[u]=dep[fath]+1;
	fa[u]=fath;
	for(auto v:g[u]){
		if(v==fath)continue;
		dfs1(v,u);
		if(dep[v]>dep[rt])rt=v;
	}
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)g[i].clear(),dep[i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs1(c,0);
	cout<<dep[rt]/3<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T=1;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 1
8 2
1 2
1 4
1 6
2 3
6 7
7 8
4 5
*/
