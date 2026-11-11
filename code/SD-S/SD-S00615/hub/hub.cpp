#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+100;
int n,k;
vector<int> g[N];
vector<int> deg[N];
int ans=0;
bool vis[N];
inline int dfs1(int x,int f){
	if (vis[x]) return 0;
	int res=0;
	for (int v:g[x]){
		if (v==f) continue;
		res=max(res,dfs1(v,x)+1);
	}
	return res;
}
bool vis2[N];
inline void clear(int u){
	vis2[u]=0;
	for (int v:g[u]){
		if (vis2[v]) clear(v);
	}
}
int check(){
	int now=0;
	for (int i=1;i<=n;++i) vis2[i]=vis[i];
	int sum=0;
	for (int i=1;i<=n;++i) now+=vis[i];
	if (now!=k) return 1e9;
	for (int i=1;i<=n;++i){
		sum=max(sum,dfs1(i,0));
	}
	int cnt=0;
	for (int i=1;i<=n;++i){
		if (vis2[i]) cnt++,clear(i);
	}
	if (cnt>2) return 1e9;
	return sum;
}
void dfs(int dep,int tmp){
	if (tmp>k) return;
	if (dep==n+1){
		ans=min(ans,check());
		return;
	}
	vis[dep]=1;
	dfs(dep+1,tmp+1);
	vis[dep]=0;
	dfs(dep+1,tmp);
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for (int i=1;i<=n;++i) vis[i]=0,g[i].clear(),deg[i].clear();
	for (int i=1;i<n;++i){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;cin>>c>>T;
	while (T--) solve(); 
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
