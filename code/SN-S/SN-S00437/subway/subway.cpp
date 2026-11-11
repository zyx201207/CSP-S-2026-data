// jrlzy 2 subway

#include <bits/stdc++.h>
#define LL long long
#define SH short
#define DB long double
#define inf (1e18)
const int N=500005,M=505;
using namespace std;
int C,n,m,d,q,a[N];
struct nd { int i,w; }; basic_string <nd> p[N];
LL ds[M][M];
void mian ()
{
	cin>>C>>n>>m>>d>>q; for (int i=1;i<=m;++i) cin>>a[i];
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) ds[i][j]=inf;
	for (int i=1,k;i<=n;++i) { cin>>k; for (int u,t;k--;) cin>>u>>t,p[u]+=(nd){i,t}; }
	for (int i=1;i<=m;++i) for (nd x:p[i]) for (nd y:p[i]) ds[x.i][y.i]=min(ds[x.i][y.i],1LL*x.w+y.w);
	for (int i=1;i<=n;++i) ds[i][i]=0;
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) ds[i][j]=min(ds[i][j],ds[j][i]);
	for (int k=1;k<=n;++k) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) ds[i][j]=min(ds[i][j],ds[i][k]+ds[j][k]);
	for (int u,v;q--;)
	{
		cin>>u>>v; LL t=inf;
		for (nd x:p[u]) for (nd y:p[v]) t=min(t,x.w+ds[x.i][y.i]+y.w);
		cout<<t+a[u]+a[v]<<'\n';
	}
	
}
int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int T; cin>>T; while (T--)
		mian();
	exit(0);
}


/*
#include <bits/stdc++.h>
#define LL long long
#define SH short
#define DB long double
#define inf (1e18)
const int N=500005;

using namespace std;
int C,n,m,d,Q,a[N];
struct eg { int v,w; }; vector <eg> E[N<<1]; int z;
struct qu { int u,i; }; vector <qu> p[N]; LL ot[N];
int vs[N<<1]; LL ds[N<<1]; priority_queue<pair<LL,int>>q;
void dij (int S)
{
	for (int i=1;i<=z;++i) vs[i]=0,ds[i]=inf;
	while (q.size()) q.pop();
	q.push({-(ds[S]=0),S}); while (q.size())
	{
		int u=q.top().second; q.pop(); 
		if (vs[u]) continue; vs[u]=1;
		for (eg e:E[u])
		{
			int v=e.v; LL w=ds[u]+e.w;
			if (ds[v]>w) q.push({-(ds[v]=w),v});
		}
	}
}
void mian ()
{
	cin>>C>>m>>n>>d>>Q; for (int i=1;i<=n;++i) cin>>a[i];
	z=n; for (int q=1,k,l;q<=m;++q)
	{
		cin>>k,l=0,++z; for (int u,t;k--;)
		{
			cin>>u>>t; E[z].push_back({u,t}); E[u].push_back({z,t}); l=u;
		}
	}
	for (int i=1,x,y;i<=Q;++i) cin>>x>>y,p[x].push_back({y,i});
	for (int u=1,v;u<=n;++u) if (p[u].size())
	{
		dij(u); for (qu t:p[u]) ot[t.i]=ds[t.u]+a[u]+a[t.u];
	}
	for (int i=1;i<=Q;++i) cout<<ot[i]<<'\n';
}
int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway3.in","r",stdin);
	freopen("subway3.out","w",stdout);
//	int T; cin>>T; while (T--)
		mian();
	exit(0);
}
*/
