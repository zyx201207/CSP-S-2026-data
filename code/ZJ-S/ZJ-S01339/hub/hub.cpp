#include<bits/stdc++.h>
using namespace std;
const int N=100+100;
vector<int>w[N];
int n,k;
int vis[N];
int minn[N];
int bfs(int x)
{
	queue<int>q;
	q.push(x);
	for(int i=1;i<=n;i++)
	minn[i]=1e9;
	minn[x]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(vis[x])
		return minn[x];
		for(int i=0;i<w[x].size();i++)
		{
			int v=w[x][i];
			if(minn[x]+1<minn[v])
			minn[v]=minn[x]+1,q.push(v);
		}
	}
}
int fa[N];
int ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x,int sum)
{
	if(x==n+1)
	{
		if(sum!=k)
		return;
		int res=0;
		for(int i=1;i<=n;i++)
		{
		if(!vis[i])
			res=max(bfs(i),res);
			fa[i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<w[i].size();j++)
			{
				if(find(i)!=find(w[i][j])&&vis[i]&&vis[w[i][j]])
				fa[find(i)]=find(w[i][j]);
			}
		}
		int pq=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]&&find(i)==i)
			pq++;
		}
		if(pq<=2)
		ans=min(ans,res);
		return;
	}
	vis[x]=0;
	dfs(x+1,sum);
	vis[x]=1;
	dfs(x+1,sum+1);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--)
   {
   
   	cin>>n>>k;
   	for(int i=1;i<n;i++)
   	{
   		int u,v;
   		cin>>u>>v;
   		w[u].push_back(v),w[v].push_back(u);
	}
	ans=1e9;
	dfs(1,0);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	w[i].clear();
   }
	return 0;
}
