#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[2000001],dist[5001],cnt[5001],in[5001],ord[5001],d,t,c;
vector<int> g[5001],mn[5001];
set<int> pre[5001];
void djs(int s)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=0x3f3f3f3f;
	}
	priority_queue<pair<int,int>> pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty())
	{
		pair<int,int> pp=pq.top();
		pq.pop();
		int u=pp.second;
		if(-pp.first!=dist[u])	continue;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				pq.push({-dist[v],v});
				pre[v].clear();
				pre[v].insert(u);
			}
			else if(dist[v]==dist[u]+1)
			{
				pre[v].insert(u);
			}
		}
	}
}
void build()
{
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(auto it=pre[i].begin();it!=pre[i].end();it++)
		{
			mn[*it].push_back(i);
			in[i]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			ord[++tot]=i;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<mn[u].size();i++)
		{
			int v=mn[u][i];
			if(--in[v]==0)
			{
				ord[++tot]=v;
				q.push(v);
			}
		}
	}
}
long long getans(int s)
{
	long long res=0;
	cnt[s]=1;
	for(int i=1;i<=n;i++)
	{
		int u=ord[i];
		for(auto it=pre[u].begin();it!=pre[u].end();it++)
		{
			cnt[u]+=cnt[*it];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==2)
		{
			res++;
		}
	}
	return res;
}
int isap()
{
	int delta=x[2]-x[1];
	for(int i=1;i<n;i++)
	{
		if(x[i+1]-x[i]!=delta)
		{
			return -1;
		}
	}
	return delta;
}

signed main()
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
			cin>>x[i];
		}
		int delta=isap();
		if(n<=5000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]>x[i]+d)
					{
						break;
					}
					else
					{
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					mn[j].clear();
					pre[j].clear();
					ord[j]=0;
					cnt[j]=0;
					in[j]=0;
				}
				djs(i);
				build();
				ans+=getans(i);
			}
			cout<<ans/2<<'\n';
		}
		else if(delta!=-1)
		{
			if(d>=3*delta)
			{
				cout<<0<<'\n';
			}
			else if(d>=2*delta)
			{
				cout<<n-3<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}	
	}
	return 0;
}
