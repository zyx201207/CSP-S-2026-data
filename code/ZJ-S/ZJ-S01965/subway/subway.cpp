// subway
#include<bits/stdc++.h>
bool Mst;
using namespace std;
using ll=long long;
#define int ll
using pii=pair<int,int>;
const int N=1e3+5,M=1e6+5;
const ll inf=1e18+5;
vector<pii> vec[M];
int w0[M],g[N][N];
bool Med;
signed main()
{
//	cerr<<abs((&Med)-(&Mst))/1024.0/1024.0<<" MB"<<endl;
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tid,n,m,d,q;cin>>tid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w0[i];
	for(int i=1;i<=n;i++)
	{
		int s;cin>>s;
		for(int x,y;s--;) cin>>x>>y,vec[x].push_back({i,y});
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=inf;
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(auto eu:vec[i])
		{
			int u=eu.first,wu=eu.second;
			for(auto ev:vec[i])
			{
				int v=ev.first,wv=ev.second;
				g[u][v]=min(g[u][v],wu+wv);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
	while(q--)
	{
		int x,y,ans=inf;cin>>x>>y;
		for(auto ex:vec[x])
		{
			int u=ex.first,wu=ex.second;
			for(auto ey:vec[y])
			{
				int v=ey.first,wv=ey.second;
				ans=min(ans,g[u][v]+wu+wv);
			}
		}
		cout<<ans+w0[x]+w0[y]<<"\n";
	}
//	cerr<<clock()<<endl;
}

