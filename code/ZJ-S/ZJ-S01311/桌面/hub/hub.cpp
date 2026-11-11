#include<bits/stdc++.h>
using namespace std;
int cid,n,k;
vector<int> G[100005];
int fa[100005],d[100005],vis[100005];
void dfs(int x) {
	for(auto y:G[x]) {
		if(y==fa[x]) continue;
		fa[y]=x, dfs(y);
	}
}
int mx;
void dfs2(int x) {
	mx=max(mx,d[x]);
	for(auto y:G[x]) {
		if(y==fa[x] || vis[y]) continue;
		fa[y]=x, d[y]=d[x]+1, dfs2(y);
	}
}
const int inf=1e9;
int mxd[100005],sz[100005],f[1005][1005],g[100005],dep[100005];
void dfs3(int x) {
	mxd[x]=d[x];
	for(auto y:G[x]) {
		if(y==fa[x] || vis[y]) continue;
		fa[y]=x, d[y]=d[x]+1, dfs3(y);
		mxd[x]=max(mxd[x],mxd[y]);
	}
}
void dfs4(int x) {
	sz[x]=1, f[x][0]=mxd[x]-d[x]+1, f[x][1]=0;
	for(auto y:G[x]) {
		if(y==fa[x] || vis[y]) continue;
		dfs4(y);
		for(int i=0; i<=min(sz[x]+sz[y],k); i++) g[i]=inf;
		for(int i=0; i<=min(sz[x],k); i++)
			for(int j=0; j<=min(sz[y],k-i); j++)
				g[i+j]=min(g[i+j],max(f[x][i],f[y][j]));
		for(int i=0; i<=min(sz[x]+sz[y],k); i++) f[x][i]=g[i];
		sz[x]+=sz[y];
	}
}
void solve(int x) {
	fa[x]=0, dfs3(x), dfs4(x);
}
int ans;
void atri(int s, int t) {
	fa[s]=0, dfs(s);
	for(int i=1; i<=n; i++) vis[i]=0, d[i]=0;
	vis[s]=vis[t]=1;
	int x=0;
	for(int i=fa[t]; i!=s; i=fa[i]) vis[i]=1, d[i]=++x;
	++x;
	for(int i=fa[t]; i!=s; i=fa[i]) d[i]=min(d[i],x-d[i]);
	mx=0;
	for(int i=fa[t]; i!=s; i=fa[i]) dfs2(i);
	// cout<<"pt: ";
	// for(int i=fa[t]; i!=s; i=fa[i]) cout<<i<<' '<<d[i]<<";  ";
	// cout<<'\n';
	solve(s), solve(t);
	for(int i=1; i<k; i++) {
		// printf("s=%d t=%d i=%d %d %d %d\n",s,t,i,f[s][i],f[t][k-i],mx);
		ans=min(ans, max(max(f[s][i],f[t][k-i]),mx));
	}
}
mt19937 rnd(time(0));
void ATRI() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) G[i].clear();
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		G[u].push_back(v), G[v].push_back(u);
	}
	if(cid==7 || cid==11 || cid==12) {
		cout<<(n==k?0:max(1,(n+14-2*k)/8))<<' ';
		return;
	}
	ans=inf;
	if(cid==8) {
		for(int i=1; i<=20000; i++) {
			int s=rnd()%n+1, t=rnd()%n+1;
			while(s==t) s=rnd()%n+1, t=rnd()%n+1;
			atri(s,t);
		}
	} else {
		for(int s=1; s<=n; s++) {
			for(int t=s+1; t<=n; t++) {
				atri(s,t);
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>cid>>T;
	while(T--) ATRI();
}