#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+10,maxn=505;
int c,n,m,d,q;//n<=500
int k[maxn];
int dis[maxn][maxn];
/*
c 无用 
n 点块<=500
m 点数
d 最大经过数
q 问数 
*/
//map<int,bool>mp;
int mp[maxm];
map<int,int>mp_point[maxn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int>a(m+5);
	vector<vector<int>>g(n+5),cost(n+5);//g图 cost花费 
	vector<vector<int>>point_belong(m+5);
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		g[i].resize(k[i]+5);
		cost[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++)
		{
			cin>>g[i][j]>>cost[i][j];
			mp_point[i][g[i][j]]=j;
			point_belong[g[i][j]].push_back(i);
		}
	}
	/*
	c 无用 
	n 点块<=500
	m 点数
	d 最大经过数
	q 问数 
	*/
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			mp[g[i][j]]=i;
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
				continue;
			}
			int bridge_cost_between_kuai=1e18;
			for(int x=1;x<=k[j];x++)
			{
				int v=g[j][x];
				if(mp[v]==i)
				{
					bridge_cost_between_kuai=min(bridge_cost_between_kuai,cost[i][mp_point[i][v]]+cost[j][x]);
				}
			}
			dis[i][j]=bridge_cost_between_kuai;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto go_kuai:point_belong[x])
		{
			for(auto arr_kuai:point_belong[y])
			{
				int f1=go_kuai,f2=arr_kuai;
				ans=min(ans,cost[f1][mp_point[f1][x]]+cost[f2][mp_point[f2][y]]+dis[f1][f2]);
			}			
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
} 
/*
c 无用 
n 点块<=500
m 点数
d 最大经过数
q 问数 
*/
