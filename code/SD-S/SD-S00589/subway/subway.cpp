#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N=6e5+5;
#define pii pair<ll,ll>
#define x first
#define y second
inline void read(ll &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
}
ll c,n,m,d,q,w[N],dis[505][505];
vector<pii> g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++)
		read(w[i]);//cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k;read(k);//cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll a,t;
			read(a),read(t);//cin>>a>>t;
			g[a].emplace_back(i,t);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
			for(int k=j+1;k<g[i].size();k++)
				dis[g[i][j].x][g[i][k].x]=min(dis[g[i][j].x][g[i][k].x],g[i][j].y+g[i][k].y);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		ll u,v,an=1e18;
		read(u),read(v);//cin>>u>>v;
		for(pii U:g[u])
			for(pii V:g[v])
				an=min(an,dis[U.x][V.x]+U.y+V.y);
		cout<<(an+w[u]+w[v])<<"\n";
	}
	return 0;
}
