#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define test(x) cerr << "Test: " << (x) << '\n';
#define debug test("qwq")
#define pii pair<int,int>
#define eb emplace_back
#define F first
#define S second
typedef long long ll;
const int N = 5019;
int siz[N],n,k,f[N][N],g[N][N],dep[N],mxdep[N],tmp[N],t2[N];
vector<int> G[N];
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	mxdep[u]=dep[u];
	for (int v:G[u]) {
		dfs(v,u);
		for (int i=0;i<=siz[u]+siz[v];++i) tmp[i]=t2[i]=1e9;
		for (int x=0;x<=siz[u];++x) for (int y=0;y<=siz[v];++y) tmp[x+y]=min(tmp[x+y],max(f[u][x],f[v][y]));
		for (int x=0;x<=siz[u];++x) for (int y=0;y<=siz[v];++y) t2[x+y]=min(t2[x+y],min(max(f[u][x],g[v][y]),max(g[u][x],f[v][y])));
		siz[u]+=siz[v];
		for (int i=0;i<=siz[u];++i) f[u][i]=tmp[i],g[u][i]=t2[i];
		mxdep[u]=max(mxdep[v],mxdep[u]);
	}
	for (int i=siz[u];~i;--i) f[u][i]=f[u][i-1]+1,g[u][i]=g[u][i-1]+1;
	g[u][0]=f[u][0]=mxdep[u]-dep[u];
	++siz[u];
}
void solve() {
	scanf("%d%d",&n,&k);
	for (int i=1,u,v;i<n;++i) {
		scanf("%d%d",&u,&v);
		G[u].eb(v); G[v].eb(u);
	}
	dfs(1,0);
	printf("%d\n",f[1][k]);
	for (int i=0;i<=n;++i) for (int j=0;j<=n;++j) f[i][j]=g[i][j]=0;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tc,t;
	scanf("%d%d",&tc,&t);
	while (t--) solve();
	return 0;
}
/*
g++ A.cpp -o tmp &&./tmp
*/