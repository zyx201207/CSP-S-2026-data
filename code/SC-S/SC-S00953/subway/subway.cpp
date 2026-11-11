#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,pds;
int f1=0,f2=0;
int a[500005];
int k[505];
vector<pair<int,int> > t[505];
vector<pair<int,int> > mp[5005];
vector<int> mp1[30005];
int dis1[30005],vis1[30005];
int dis[5005],vis[5005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>pds;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			if(y!=f1)
			{
				f2++;
				f1=y;
			}
			t[i].push_back({x,y});
		}
	}
	if(f2==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<k[i];j++)
			{
				mp1[m+i].push_back(t[i][j].first);
				mp1[t[i][j].first].push_back(m+i);
			}
		}
		queue<int> q;
		while(pds--)
		{
			int u,v;
			cin>>u>>v;
			q.push(u);
			memset(dis1,0x3f,sizeof dis1);
			memset(vis1,0,sizeof vis1);
			dis1[u]=0;
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				for(int i=0;i<mp1[x].size();i++)
				{
					if(vis1[mp1[x][i]]) continue;
					vis1[mp1[x][i]]=1;
					dis1[mp1[x][i]]=dis1[x]+1;
					q.push(mp1[x][i]);
				}
			}
			cout<<a[u]+a[v]+f1*dis1[v]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k[i];j++)
		{
			mp[m+i].push_back({t[i][j].first,t[i][j].second});
			mp[t[i][j].first].push_back({m+i,t[i][j].second});
		}
	}
	while(pds--)
	{
		priority_queue<pair<int,int> > q;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		int u,v;
		cin>>u>>v;
		dis[u]=0;
		q.push({0,u});
		while(!q.empty())
		{
			int x=-q.top().first,y=q.top().second;
			q.pop();
			if(vis[y]) continue;
			vis[y]=1;
			for(int i=0;i<mp[y].size();i++)
			{
				if(dis[mp[y][i].first]>dis[y]+mp[y][i].second)
				{
					dis[mp[y][i].first]=dis[y]+mp[y][i].second;
					q.push({-dis[mp[y][i].first],mp[y][i].first});
				}
			}
		}
		cout<<dis[v]+a[u]+a[v]<<'\n';
		
	}
	return 0;
}