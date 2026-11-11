#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
long long a[N+5],dis[N+5];
bool flag[N+5],vis[N+5];
vector<long long>g[N+5];
long long n,k;
long long ans=1e18;
long long bfs(long long s,long long t)
{
	for(long long i=1;i<=n;i++) dis[i]=-1;
	queue<long long>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		if(u==t) return dis[t];
		for(long long i=0;i<g[u].size();i++)
		{
			long long v=g[u][i];
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
void find(long long x)
{
	vis[x]=true;
	for(long long i=1;i<g[x].size();i++)
	{
		long long u=g[x][i];
		if(!vis[u]&&flag[u]) find(u);
	}
}
bool check()
{
	for(long long i=1;i<=n;i++) vis[i]=false;
	long long cnt=0;
	for(long long i=1;i<=k;i++)
	{
		if(!vis[a[i]]&&cnt<2)
		{
			find(a[i]);
			cnt++;
		}
		else if(!vis[a[i]]&&cnt>=2) return false;
	}
	return true;
}
long long get()
{
	long long res=-1;
	for(long long i=1;i<=n;i++)
	{
		long long sum=1e18;
		for(long long j=1;j<=k;j++)
		{
			sum=min(sum,bfs(i,a[j]));
		}
		res=max(res,sum);
	}
	return res;
}
void dfs(long long x)
{
	if(x>k)
	{
		if(check())
		{
			ans=min(ans,get());
		}
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=true;
			a[x]=i;
			dfs(x+1);
			flag[i]=false;
		}
	}
}
int main()
{	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=1e18;
		for(long long i=1;i<=n;i++) g[i].clear();
		for(long long i=1;i<n;i++)
		{
			long long u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		dfs(1);
		cout<<ans<<endl; 
	}
	return 0;
}
