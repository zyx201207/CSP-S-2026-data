#include<bits/stdc++.h>
using namespace std;
int C,T,n,K;
struct edge
{
	int to,nxt;
}e[200005];
int tot,h[100005];
void add(int u,int v)
{
	e[++tot]={v,h[u]};
	h[u]=tot;
}
bool t[100005],vis[100005];
int dis[5005][5005];
void dfs0(int rt,int x,int fx)
{
	for(int i=h[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(y==fx) continue;
		dis[rt][y]=dis[rt][x]+1;
		dfs0(rt,y,x);
	}
}
int mn[50005];
void dfs(int x,int fx)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(y==fx) continue;
		if(t[y]) dfs(y,x);
	}
}
int ans=1e9;
void ff(int k,int nw)
{
	if(k>n||nw>=K)
	{
		for(int i=1;i<=n;i++) vis[i]=0,mn[i]=1e9;
		int c=0;
		for(int i=1;i<=n;i++){
			if(t[i]&&!vis[i])
			{
				c++;
				if(c>2) return ;
				dfs(i,0);
				for(int j=1;j<=n;j++)
					mn[j]=min(mn[j],dis[i][j]);
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)
			if(!t[i]) res=max(res,mn[i]);
		ans=min(ans,res);
		return ;
	}
	if(nw<K)
	{
		t[k]=1;
		ff(k+1,nw+1);
	}
	t[k]=0;
	ff(k+1,nw);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d",&n,&K);
		tot=0;
		for(int i=1;i<=n;i++) h[i]=0;
		int ui,vi;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&ui,&vi);
			add(ui,vi);
			add(vi,ui);
		}
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			dfs0(i,i,0);
		}
		ans=1e9;
		ff(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
