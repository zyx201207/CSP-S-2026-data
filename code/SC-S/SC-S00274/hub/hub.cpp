#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=3010;
int c,t,n,k,ans;
bool flag[N],f[N],f2[N];
int a[N],tot;
int dep[N],fa[N][20];
vector<int> g[N];
void dfs1(int x)
{
	if(f[x]) return;
	f[x]=1;
	for(int to:g[x])
	{
		if(flag[to]) continue;
		dfs1(to);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]!=dep[y])
		x=fa[x][0];
	if(x==y) return x;
	while(x!=y) x=fa[x][0],y=fa[y][0];
	return x;
}
void check()
{
	memset(f2,0,sizeof(f2));
	tot=0;int sum=0;
	for(int i=1;i<=n;i++)
		if(flag[i]) a[++tot]=i,f[i]=0,f2[i]=1;
	for(int i=1;i<=tot;i++)
		if(!f[i]) dfs1(i),sum++;
	if(sum>2) return;
	for(int i=1;i<=n;i++)
	{
		if(f2[i]) continue;
		int res=0x3f3f3f3f;
		for(int j=1;j<=n;j++)
		{
			if(i==j||f2[j]) continue;
			int dis=dep[i]+dep[j]-2*dep[LCA(i,j)];
			res=min(res,dis);
		}
		sum=max(sum,res);
	}
	ans=min(ans,sum);
}
void dfs(int x,int cnt)
{
	if(cnt==k)
	{
		check();
		return;
	}
	if(x>n) return;
	flag[x]=1,dfs(x+1,cnt+1);
	flag[x]=0,dfs(x+1,cnt);
}
void pre(int x,int fat)
{
	dep[x]=dep[fat]+1,fa[x][0]=fat;
	for(int to:g[x])
	{
		if(to==fat) continue;
		pre(to,x);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0x3f3f3f3f;
		scanf("%d%d",&n,&k);
		memset(dep,0,sizeof(dep));
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].emplace_back(y);
			g[y].emplace_back(x);
		}
		pre(1,0);
		for(int j=1;j<=19;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}