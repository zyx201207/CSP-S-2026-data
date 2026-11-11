#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,d,ans;
int x[2000005];
vector<int> g[2000005];
int dis[2000005];
int cnt[2000005];
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		pair<int,int> tmp=pq.top();
		pq.pop();
		int d=tmp.first,u=tmp.second;
		if(d!=dis[u]) { cnt[u]=1;continue; }
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[v]==dis[u]+1)
			{
				cnt[v]++;
				pq.push({dis[v],v});
			}
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=1;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				int dis=abs(x[i]-x[j]);
				if(dis<=d) g[i].push_back(j),g[j].push_back(i);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
