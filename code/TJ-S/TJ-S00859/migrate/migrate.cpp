#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
struct nod
{
	ll v,w;
	friend bool operator<(const nod &a,const nod &b)
	{
		return a.w>b.w;
	}
};
vector<nod>g[N];
ll dis[N],ans[N],cnt;
bool vis[N];
void dijkstra(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	priority_queue<nod>q;
	dis[st]=0;
	q.push({st,dis[st]});
	while(!q.empty())
	{
		nod cur=q.top();
		q.pop();
		int u=cur.v;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto e:g[u])
		{
			int v=e.v,w=e.w;
			if(vis[v])
			{
				continue;
			}
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				ans[v]=1;
				q.push({v,dis[v]});
			}
			else if(dis[u]+w==dis[v])
			{
				ans[v]++;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
int n,m,x[N],c,t,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=1;j<=i;j++)
			{
				if(i!=j&&x[i]-x[j]<=d)
				{
					g[i].push_back({j,1});
					g[j].push_back({i,1});
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			for(int j=i+3;j<=n;j++)
			{
				if(ans[j]==2)
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
}
