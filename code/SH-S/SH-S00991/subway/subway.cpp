#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<int> to[M];
vector<ll> tl[M];
void chkmin(ll &x,ll y)
{
	if(y<x)x=y;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			to[a].push_back(i);
			tl[a].push_back(t);
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<to[i].size();j++)
			for(int k=0;k<j;k++)
			{
				int u=to[i][j],v=to[i][k];
				ll tmp=tl[i][j]+tl[i][k];
				chkmin(dis[u][v],tmp);
				chkmin(dis[v][u],tmp);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				chkmin(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--)
	{
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for(int i=0;i<to[x].size();i++)
			for(int j=0;j<to[y].size();j++)
				chkmin(ans,dis[to[x][i]][to[y][j]]+tl[x][i]+tl[y][j]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
