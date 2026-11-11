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
const int N = 5e5 + 19;
int tc,n,m,d,q,w[N],deg[N];
ll dis[520][520];
vector<int> r[520];
vector<pii> G[N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&tc,&n,&m,&d,&q);
	for (int i=1;i<=m;++i) scanf("%d",&w[i]);
	for (int i=1;i<=n;++i) {
		int k; scanf("%d",&k);
		for (int j=0;j<k;++j) {
			int a,t; scanf("%d%d",&a,&t);
			r[i].eb(t); G[a].eb(i,j); ++deg[a];
		}
	}
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=n;++i) dis[i][i]=0;
	for (int i=1;i<=m;++i) {
		// test(deg[i]);
		for (int x=0;x<deg[i];++x) for (int y=0;y<deg[i];++y) {
			ll A=r[G[i][x].F][G[i][x].S],B=r[G[i][y].F][G[i][y].S];
			int u=G[i][x].F,v=G[i][y].F;
			// test(A+B);
			dis[u][v]=min(dis[u][v],A+B);
		}
	}
	// for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) printf("%lld%c",dis[i][j]," \n"[j==n]);
	for (int k=1;k<=n;++k) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--) {
		int u,v; scanf("%d%d",&u,&v);
		ll ans=1e18;
		for (int x=0;x<deg[u];++x) for (int y=0;y<deg[v];++y) {
			int A=r[G[u][x].F][G[u][x].S],B=r[G[v][y].F][G[v][y].S];
			ans=min(ans,dis[G[u][x].F][G[v][y].F]+A+B);
		}
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
g++ A.cpp -o tmp &&./tmp
*/