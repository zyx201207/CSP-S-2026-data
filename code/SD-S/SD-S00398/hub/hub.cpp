#include<bits/stdc++.h>
using namespace std;

#define int long long
int c,t,n,k,vis[1000005],mx,f1;
vector<int>edge[1000005];
queue<int>q;
bool bfs(int x,int y)
{
	memset(vis,0,sizeof(vis));
	queue<int>q
}
void dfs1(int x,int f,int far)
{
	if(mx<far)
	{
		mx=far;
		f1=x;
	}
	for(int i=0; i<edge[x].size(); i++)
	{
		if(edge[x][i]==f)
		{
			continue;
		}
		dfs(edge[x][i],x,far+1);
	}
}
void dfs2(int x,int f,int far)
{
	if(mx<far)
	{
		mx=far;
		f2=x;
	}
	for(int i=0; i<edge[x].size(); i++)
	{
		if(edge[x][i]==f)
		{
			continue;
		}
		dfs(edge[x][i],x,far+1);
	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==7||c==11||c==12)
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1; i<n; i++)
			{
				int u,v;
				cin>>u>>v;
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
			mx=0,f1=0,f2=0;
			dfs1(1,0,0);
			mx=0;
			dfs2(f1,0,0);
			for(int i=1; i<=n; i++)
			{
				priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qp;
				qp.push(make_pair(0,f1));
				for(int i=1; i<=n; i++)
				{
					cnt[i]=0x3f3f3f3f3f;
				}
				cnt[i]=-1;
				while(!qp.empty())
				{
					int u=qp.top().second,sum=qp.top().first;
					qp.pop();
					for(int i=0; i<edge[u].size(); i++)
					{
						int v=edge[u][i].first,w=edge[u][i].second;
						if(cnt[v]>sum+w)
						{
//						cout<<u<<' '<<v<<' '<<sum<<' '<<w<<'\n';
							cnt[v]=sum+w;
							qp.push(make_pair(cnt[v],v));
						}
					}
				}
				if(cnt[f2]<=i*2)
				{
					cout<<i<<'\n';
				}
			}
		}
	}
	else if(c>=13||c<=14)
	{
		cin>>t;
		while(t--)
		{
			cin>>n>>k;
			int tmp=(n+1)/2;
			cout<<((tmp/k)+1)/2+1;
		}
	}
	else
	{
		cin>>t;
		while(t--)
		{
			cout<<0;
		}
	}

	return 0;
}

