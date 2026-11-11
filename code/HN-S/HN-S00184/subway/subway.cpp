#include<bits/stdc++.h>
#define ll long long
#define pil pair<int,ll>
#define fi first
#define se second
using namespace std;
const int M=5e5+5,N=5e2+5;
const ll inf=1e18;
int n,m,d,q;
ll w[M],dis[N][N];
vector<pil> vt[M];
void solve()
{
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int x,y;
		ll z;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>y>>z;
			for(auto v:vt[y])
			{
				dis[i][v.fi]=min(dis[i][v.fi],z+v.se);
				dis[v.fi][i]=dis[i][v.fi];
			}
			vt[y].emplace_back(i,z);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		ll res=inf;
		cin>>x>>y;
		if(x==y)
		{
			cout<<"0\n";
			continue;
		}
		for(auto u:vt[x])
			for(auto v:vt[y])
				res=min(res,w[x]+w[y]+u.se+v.se+dis[u.fi][v.fi]);
		cout<<res<<'\n';
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1,C;
	cin>>C;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
