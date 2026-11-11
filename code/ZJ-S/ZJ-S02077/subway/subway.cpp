//15:30 开始写T2
//注意到m较大，但是n很小
//那么计算每两个线路的距离即可 
//T2<T1 
//16:42终于写完了，我去怎么这么晚了。 
//太好了，调完了
#include<bits/stdc++.h>
//#define DEBUG 
#define N 500005
#define M 505
using namespace std;
int c,n,m,d,q;
long long w[N],ed[M][M],dis[M][M],vis[M][M];
vector<pair<int,long long> > a[N];
int main()
{
	#ifndef DEBUG
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int x,t;
			cin >> x >> t;
			a[x].push_back({i,t});
		}
	}
	memset(ed,0x3f,sizeof(ed));
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= m;i++)
	{
		for(auto j:a[i])
		{
			for(auto k:a[i])
			{
				if(j.first!=k.first)
				{
					ed[j.first][k.first]=ed[k.first][j.first]=min(j.second+k.second,ed[k.first][j.first]);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		priority_queue<pair<long long,int>>s;
		s.push({0,i});
		dis[i][i]=0;
		while(!s.empty())
		{
			int u=s.top().second;
			s.pop();
			if(vis[i][u])
			{
				continue;
			}
			vis[i][u]=1;
			for(int v = 1;v <= n;v++)
			{
				if(dis[i][v]>dis[i][u]+ed[u][v])
				{
					dis[i][v]=dis[i][u]+ed[u][v];
					s.push({-ed[i][v],v});
				}
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		long long ans=1e18;
		for(auto j:a[x])
		{
			for(auto k:a[y])
			{
				ans=min(ans,dis[j.first][k.first]+j.second+k.second);
			}
		}
		cout << ans+w[x]+w[y] <<'\n';
	}
}
