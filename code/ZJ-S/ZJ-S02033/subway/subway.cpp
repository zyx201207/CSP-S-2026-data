#include<bits/stdc++.h>
using namespace std;
#define int long long
#define io(name) freopen(name".in","r",stdin);freopen(name".out","w",stdout)
signed c,n,m,d,q;
int w[500010];
signed k[510];
vector<pair<signed,int>>v[500010];
int dis[510][510];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    io("subway");
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
    	signed a,t;
    	for(int j=1;j<=k[i];j++)
    	{
    		cin>>a>>t;
    		v[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		dis[i][j]=(i==j?0:1e18);
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:v[i])for(auto y:v[i])if(x.first!=y.first)
		{
			int xf=x.first,xs=x.second,yf=y.first,ys=y.second;
			dis[xf][yf]=min(dis[xf][yf],xs+ys);
		}
	}
	for(int i=1;i<=n;i++)for(int k=1;k<=n;k++)for(int j=1;j<=n;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto i:v[x])for(auto j:v[y])
		{
			ans=min(ans,dis[i.first][j.first]+i.second+j.second);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
