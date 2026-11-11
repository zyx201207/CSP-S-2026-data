#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;
const int N=505,M=5e5+5;
int C,n,m,d,q,k[N],w[M];
ll dis[N][N];
vector<pair<int,int>> bel[M];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ll x=dis[i][j],y=dis[i][k]+dis[k][j];
				dis[i][j]=(x<y?x:y);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			bel[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto u:bel[i])
		{
			for(auto v:bel[i])
			{
				if(u==v) continue;
				int a=u.fir,x=u.sec,b=v.fir,y=v.sec;
				ll n1=dis[a][b],m1=x+y;
				dis[a][b]=(n1<m1?n1:m1);
				ll n2=dis[b][a],m2=x+y;
				dis[b][a]=(n2<m2?n2:m2);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		ll res=0x3f3f3f3f3f3f3f3f;
		for(auto p1:bel[x])
		{
			for(auto p2:bel[y])
			{
				int u=p1.fir,v=p2.fir,a=p1.sec,b=p2.sec;
				ll n1=res,m1=dis[u][v]+a+b;
				res=(n1<m1?n1:m1);
			}
		}
		ans+=res;
		cout<<ans<<'\n';
	}
	return 0;
}
