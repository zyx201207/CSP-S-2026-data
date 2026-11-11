#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,w[N],x,y,dis[N];
bool vis[N];
vector<pair<int,int>> g[N];
struct node
{
	int k,a[25],t[25];
}s[N];
int check(int sta1,int end1)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=1;i<=n*n;i++) dis[i]=1e18;
	dis[sta1]=0;
	pq.push({0,sta1});
	vis[sta1]=1;		
	while(pq.size())
	{
		int u=pq.top().second;
		pq.pop();
		vis[u]=1;
		for(auto t:g[u])
		{
			int v=t.first,w=t.second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					vis[v]=1;
					pq.push({dis[v],v});	
				}
			}
		}	
	}
	return dis[end1];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
		cin>>w[i];	
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].k;	
		for(int j=1;j<=s[i].k;j++)
		{
			cin>>s[i].a[j]>>s[i].t[j];
		}		
		for(int j=1;j<=s[i].k;j++)
			for(int l=1;l<=s[i].k;l++)
				if(l!=j)
				{
					g[s[i].a[l]].push_back({s[i].a[j],s[i].t[j]+s[i].t[l]});
					g[s[i].a[j]].push_back({s[i].a[l],s[i].t[j]+s[i].t[l]});
				}
	}
	cnt=n*n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=s[i].k;j++)
			g[cnt++].push_back({s[i].a[j],w[i]});
	}
	while(q--)
	{
		cin>>x>>y;	
		cout<<check(x,y)<<endl;
	}		
} 
