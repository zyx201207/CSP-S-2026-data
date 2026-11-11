#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
ll w[500100],dis[510][510];
struct node
{
	int id;
	ll t;
};
vector<node>e[500100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;ll t;
			cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(node x:e[i])
		{
			for(node y:e[i])
			{
				if(x.id==y.id) continue;
				dis[x.id][y.id]=min(dis[x.id][y.id],x.t+y.t);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=8e18,a,b;
		for(node i:e[x])
		{
			for(node j:e[y])
			{
				if(dis[i.id][j.id]<ans)
				{
					ans=dis[i.id][j.id];
					a=i.t,b=j.t;
				}
			}
		}
		ans+=a+b+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
