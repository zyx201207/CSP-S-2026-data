#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
struct E{int v,w;};
int a[M],d[N][N];
vector<E>g1[N],g2[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _,n,m,q;
	cin>>_>>n>>m>>_>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int l;cin>>l;
		for(int j=1;j<=l;j++)
		{
			int v,w;
			cin>>v>>w;
			g1[i].push_back({v,w});
			g2[v].push_back({i,w});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(auto[v1,w1]:g1[i])
		{
			for(auto[v,w]:g2[v1])
			{
				int x=w1+w;
				d[i][v]=min(d[i][v],x);
				d[v][i]=min(d[v][i],x);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		int ans=a[u]+a[v];
		int mn=1e18;
		for(auto[v1,w1]:g2[u])
		{
			for(auto[v2,w2]:g2[v])
			{
				mn=min(mn,w1+w2+d[v1][v2]);
			}
		}
		ans+=mn;
		printf("%lld\n",ans);
	}
}
