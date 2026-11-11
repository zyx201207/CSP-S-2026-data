//这不一眼最短路吗，看我直接AC
//?完蛋没复习啊啊啊啊 AFO qmq
//24 pts
#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500005];
int k[505];
vector<pair<int,int>>g[500005];
priority_queue<pair<int,int>>qu;
vector<int> a[505],t[505];
int dis[500005];
bool vis[500005];
int s,tt,ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x;
			cin>>x;
			a[i].push_back(x);
			int y;
			cin>>y;
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int e=j+1;e<a[i].size();e++)
			{
				if(j!=e)
				{
					int time=t[i][j]+t[i][e];
					g[a[i][j]].push_back({a[i][e],time});
					g[a[i][e]].push_back({a[i][j],time});
				}
			}
		}
	}
	while(q--)
	{
		cin>>s>>tt;
		ans=w[s]+w[tt];
		for(int i=0;i<=m;i++)
		{
			dis[i]=INT_MAX;
			vis[i]=0;
		}
		while(!qu.empty())
		{
			qu.pop();
		}
		dis[s]=0;
		qu.push(make_pair(-dis[s],s));
		while(!qu.empty())
		{
			int h=qu.top().second;
			qu.pop();
			if(vis[h])
			{
				continue;
			}
			vis[h]=1;
			for(auto e:g[h])
			{
				if(dis[e.first]>dis[h]+e.second)
				{
					dis[e.first]=dis[h]+e.second;
					if(!vis[e.first])
					{
						qu.push({-dis[e.first],e.first});
					}
				}
			}
		}
		cout<<ans+dis[tt]<<'\n';
	}
	return 0;
} 
