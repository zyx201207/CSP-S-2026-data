#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
struct Node
{
	int x,d;
};
int n,k;
vector<int> g[N];
int f[N],d[N],minR=1e9,dep[N];
bool vis[N],visdist[N];
void dfsdep(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfsdep(v,u);
	}
}
void bfs(int x)
{
	queue<int> q;
	vis[x]=true;
	q.push(x);
	while(q.size())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(vis[v]||f[v]==0) continue;
			vis[v]=true;
			q.push(v);
		}
	}
}
bool check()//是否一个或两个联通快 
{
	int st=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		{
			st=i;
			break;
		}
	}
	memset(vis,false,sizeof(vis));
	bfs(st);
	st=1e9;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1 && !vis[i])
		{
			st=i;
			break;
		}
	}
	if(st==1e9) return true;
	bfs(st);
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1&&!vis[i]) return false;
	}
	return true;
}
int dist(int a,int b)
{
	memset(visdist,false,sizeof(visdist));
	queue<Node> q;
	q.push({a,0});
	visdist[a]=true;
	while(q.size())
	{
		Node u=q.front(); q.pop();
		int x=u.x,d=u.d;
		if(x==b) return d;
		for(int i=0;i<g[x].size();i++)
		{
			int v=g[x][i];
			if(!visdist[v])
			{
				visdist[v]=true;
				q.push({v,d+1});
			}
		}
	}
}
void dfs(int step,int cnt)
{
	if(cnt>k) return;
	if(step>n)
	{
		if(cnt==k)
		{
			if(!check()) return;
			memset(d,0,sizeof(d));
			for(int i=1;i<=n;i++)
			{
				if(f[i]==1) continue;
				int minn=1e9;
				for(int j=1;j<=n;j++)
				{
					if(f[i]==1)
					{
						minn=min(minn,dist(i,j));
					}
				}
				d[i]=minn;
			}
			int R=0;
			for(int i=1;i<=n;i++) R=max(R,d[i]);
			minR=min(minR,R);
		}
		return;
	}
	f[step]=1;//选
	dfs(step+1,cnt+1);
	f[step]=0;
	dfs(step+1,cnt); 
}
void calc()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++) g[i].clear();
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	minR=1e9;
	memset(dep,0,sizeof(dep));
	dfsdep(1,0);
	dfs(1,0);
	cout<<minR<<endl;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		calc();
	}
	return 0;
}
