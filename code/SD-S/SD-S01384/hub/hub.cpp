#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,flag=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*flag;
}
const int N  = 505;
vector<int> g[N];
bool vis[N]; 
int n,k;
int f[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int dis[N][N];
int ans;
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
void check()
{
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
		//	cout<<i<<" ";
			for(int v:g[i])
			{
				if(vis[v])merge(i,v);
			}
		}
	}//cout<<endl;
	int w=0,now=0;
	for(int i=1;i<=n;i++)if(vis[i]&&find(i)==i)++now;
//	cout<<now<<endl;
	if(now>2)return;
	for(int i=1;i<=n;i++)
	{
		int res=1e9;
		for(int j=1;j<=n;j++)
		{
	//		cout<<i<<" "<<j<<" "<<vis[i]<<" "<<vis[j]<<endl;
			if(!vis[i]&&vis[j])res=min(res,dis[i][j]);
		}
		if(!vis[i])w=max(res,w);
	}
	ans=min(ans,w);
}
void pre(int x,int fa,int rt)
{
	dis[rt][x]=dis[rt][fa]+1;
	for(int v:g[x])if(v^fa)pre(v,x,rt);
}
void dfs(int x,int cnt)
{
	if(cnt==k)
	{
		check();return;
	}
	if(x==n+1){
		if(cnt==k)check();
		return;
	}
	vis[x]=1,dfs(x+1,cnt+1);
	vis[x]=0;dfs(x+1,cnt);
}
void solve()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0;ans=1e9;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=0;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		g[u].push_back(v);g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)dis[i][0]=-1,pre(i,0,i);
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
	dfs(1,0);
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--)solve();
	return 0;
}

