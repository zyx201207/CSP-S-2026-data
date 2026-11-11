#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=105;
constexpr int inf=1e9;
int c,t,n,k;
vector<int> g[N];
int f[N];
bool vis[N];
int dis[N];
void dfs(int u,int fa){
	vis[u]=1;
	for(int v : g[u]) if(v!=fa && f[v]==1){
		dfs(v,u);
	}
}
int calc(int u){
	queue<int> q;
	q.push(u);
	fill(dis,dis+n+1,inf);
	dis[u]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(f[u]==1) return dis[u];
		for(int v : g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return 0;
}
int check(int st){
	fill(f,f+n+1,0);
	fill(vis,vis+n+1,0);
	for(int i=1;i<=n;i++){
		if((st>>(i-1))&1) f[i]=1;
	}
	int ct=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1 && !vis[i]){
			ct++;
			if(ct>2) return inf;
			dfs(i,0);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			res=max(res,calc(i));
		}
	}
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=inf;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)==k){
				ans=min(ans,check(i));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

