#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,dis[N],len[N];
long long d,a[N];
bool vis[N];
vector<int>g[N];
void dj(int st)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=0x3f3f3f3f;
		len[i]=0;
		vis[i]=0;
	}
	priority_queue<pair<int,int> >q;
	q.push({0,st});
	vis[st]=1;
	dis[st]=0;
	len[st]=1;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(auto v:g[u])
		{
			if(vis[v])
				continue;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				len[v]=len[u];
				q.push({-dis[v],v});
			}
			else if(dis[v]==dis[u]+1)
			{
				len[v]+=len[u];
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)
					break;
				g[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			dj(i);
			for(int j=i+1;j<=n;j++)
			{
				if(len[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

