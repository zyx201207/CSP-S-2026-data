#include<bits/stdc++.h>
using namespace std;
int n,k,dis[15],ans=1e9,sum1=0;
vector<int> v[15];
bool vis[15],st[15];
void bbfs(int x)
{
	queue<int> q;
	q.push(x);
	st[x]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i:v[u])
		{
			if(vis[i]&&!st[i]) 
			{
				st[i]=true; 
				q.push(i);
			}
		}
	}
}
bool check()
{
	sum1=0;
	memset(st,0,sizeof(st));
	for(int i=1;i<=n;i++)
	{
		if(vis[i]&&!st[i]) 
		{
			bbfs(i);
			sum1++;
		}
	}
	return sum1<=2;
}
int bfs()
{
	int cnt=0;
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		dis[i]=-1;
		if(vis[i]) 
		{
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cnt=max(cnt,dis[u]);
		for(int i:v[u])
		{
			if(dis[i]==-1)	
			{
				dis[i]=dis[u]+1;
				q.push(i);
			}
		}
	}
	return cnt;
}
void dfs(int x,int sum)
{
	if(x>n)
	{
		if(sum==k&&check()) ans=min(ans,bfs());
		return;
	}
	if(sum<k)
	{
		vis[x]=1;
		dfs(x+1,sum+1);
	} 
	vis[x]=0;
	dfs(x+1,sum);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	return 0;
}
