#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
const int maxn=20;
bool vis[maxn];
vector<int>g[maxn];
int u,v;
vector<int>nw;
bool invec[maxn];
int ans=1e9;
void dfs(int u,int fa)
{
	vis[u]=1;
	for (int v:g[u])
		if(v!=fa&&invec[v])
			dfs(v,u);
 } 
int bfs(int s)
{
	queue<pair<int,int>>q;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.front().first;
		int st=q.front().second;
		q.pop();
		if(invec[u])
			return st;
		for (int v:g[u])
			q.push({v,st+1});
	}
}
void solve()
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		vis[i]=0;
		invec[i]=0;
	}
	for (int x:nw)
		invec[x]=1;
	for (int x:nw)
		if(!vis[x])
		{
			dfs(x,0);
			cnt++;
		}
	if(cnt>2)
		return;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		if(invec[i])
			continue;
		sum=max(sum,bfs(i)); 
	}
	ans=min(ans,sum);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--)
	{
		ans=1e9;
		cin>>n>>k;
		for (int i=1;i<=n;i++)
			g[i].clear();
		for (int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		for (int i=0;i<(1<<n);i++)
		{
			nw.clear();
			if(__builtin_popcount(i)!=k)
				continue;
			for (int j=1;j<=n;j++)
				if(i&(1<<(j-1)))
					nw.push_back(j);
			solve();
		}
		cout<<ans<<'\n';
	}
}
