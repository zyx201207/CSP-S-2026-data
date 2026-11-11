#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int inf=1e16;
int n,k;
vector<int >e[N];
int vis[N];
int ans;
int fa[N];
int v[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v) return ;
	fa[v]=u;
}
void dfs_ck(int x,int fat){
	for(int y:e[x]){
		if(y==fat) continue;
		if(vis[x]&&vis[y]) merge(x,y);
		dfs_ck(y,x);
	}
}
int dfs_query(int x,int fa){
	if(vis[x]) return 0;
	int mn=inf;
	for(int y:e[x]){
		if(y==fa) continue;
		int now=dfs_query(y,x)+1;
		mn=min(mn,now);
	}
	return mn;
}
void check(){
	for(int i=1;i<=n;i++) fa[i]=i,v[i]=0;
	dfs_ck(1,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0) continue;
		int x=find(i);
		v[x]++;
		if(v[x]==1) ++cnt;
	}
	if(cnt>2) return ;
	int ret=0;
	for(int i=1;i<=n;i++){
		ret=max(ret,dfs_query(i,0));
	}
	ans=min(ans,ret);
}
int need=0;
void dfs_xl(int pos){
	if(need>k) return ;
	if(pos>n){
		check();
		return ;
	}
	vis[pos]=1;
	++need;
	dfs_xl(pos+1);
	--need;
	vis[pos]=0;
	dfs_xl(pos+1);
}
void solve(){
	cin>>n>>k;
	ans=inf;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	dfs_xl(1);
	cout<<ans<<'\n';
}
void clear(){
	for(int i=1;i<=n;i++) e[i].clear();
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int Case;cin>>Case;
	int T;cin>>T;
	while(T--){
		solve();
		clear();
	}
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
