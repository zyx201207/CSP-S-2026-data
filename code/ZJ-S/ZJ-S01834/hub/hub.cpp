#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],ans=0x3f3f3f3f;
int c,T,n,k,dis[1005];
bool vi[1005],vs[1005];
struct Node{
	int n,st;
};
int fd(int id)
{
	int st;
	bool vis[1005];
	memset(vis,0,sizeof(vis));
	queue<Node>nw;
	nw.push({id,0});
	while(!nw.empty())
	{
		Node ne=nw.front();
		nw.pop();
		if(vi[ne.n]==1)
		  return ne.st;
		for(int i=1;i<=a[ne.n][0];i++)
		{
			if(vis[a[ne.n][i]]==0)
			{
				nw.push({a[ne.n][i],ne.st+1});
				vis[a[ne.n][i]]=1;
			}
		}
	}
	return st;
}
void bfs(int id)
{
	queue<int>nw;
	nw.push(id);
	while(!nw.empty())
	{
		int ne=nw.front();
		nw.pop();
		vs[ne]=1;
		for(int i=1;i<=a[ne][0];i++)
		  if(vs[a[ne][i]]==0&&vi[a[ne][i]]==1)
			nw.push(a[ne][i]);
	}
	return;
}
bool ch()
{
	int kk=0;
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=n;i++)
	{
		if(vs[i]==0&&vi[i]==1)
		{
			kk++;
			if(kk>=3)
			  return 1;
			bfs(i);
		}
	}
	return 0;
}
void dfs(int id,int st)
{
	if(id>n||st==k)
	{
		if(ch())
		  return;
		int mx=0;
		for(int i=1;i<=n;i++)
		  mx=max(mx,fd(i));
		ans=min(ans,mx);
		return;
	}
	vi[id]=1;
	dfs(id+1,st+1);
	vi[id]=0;
	dfs(id+1,st);
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		int u,v;
		ans=0x3f3f3f3f;
		memset(a,0,sizeof(a));
		for(int i=0;i<=1001;i++)
		  dis[i]=vi[i]=vs[i]=0;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			a[u][++a[u][0]]=v;
			a[v][++a[v][0]]=u;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
