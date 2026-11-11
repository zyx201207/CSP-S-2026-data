#include<bits/stdc++.h>
using namespace std;
#define int long long
//void dij(int p)
//{
//	priority_queue<int>Q;
//	Q.push(p);
//	
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
//	while(Q.size())
//	{
//		int x=Q.top();
//		Q.pop();
//		if(vis[x])
//		{
//			continue;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for()
//		}
//	}
//}
int ans;
int c,d,q;
int a[100002],sum[100002],n,m;
struct P
{
	int a,t;
};
int w[500002];
vector<P>zd[502];//500002
bool cmp1(P x,P y)
{
	return x.a<y.a;
}
int Dis[1002][1002];
short gn[500002][502];
int len[500002];
int bel[500002];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int A,T;
			cin>>A>>T;
			zd[i].push_back({A,T});
		}
	}
	if((c>=1)&&(c<=11))
	{
		for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)Dis[i][j]=1e18;
		for(int i=1;i<=m;i++)Dis[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<zd[i].size();j++)
			{
				for(int k=j+1;k<zd[i].size();k++)
				{
					int u=zd[i][j].a,v=zd[i][k].a,w=zd[i][k].t+zd[i][j].t;
					Dis[u][v]=min(Dis[u][v],w);
					Dis[v][u]=min(Dis[v][u],w);
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					Dis[i][j]=min(Dis[i][k]+Dis[k][j],Dis[i][j]);
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+Dis[x][y]<<'\n';
		}
		return 0;
	}
	if((12<=c)&&(c<=19))
	{
		int mtp=zd[1][0].t;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					Dis[i][j]=1e18;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<zd[i].size();j++)
			{
				gn[zd[i][j].a][++len[zd[i][j].a]]=i;
				bel[zd[i][j].a]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<len[i];j++)
			{
				for(int k=j+1;k<=len[i];k++)
				{
					int u=gn[i][j],v=gn[i][k];
					Dis[u][v]=Dis[v][u]=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					Dis[i][j]=min(Dis[i][k]+Dis[k][j],Dis[i][j]);
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+(1+Dis[bel[x]][bel[y]])*2*mtp<<'\n';
		}
		return 0;
	}
	return 0;
}
