#include<bits/stdc++.h>
using namespace std;
int ca,t,n,k,head[20],tot=0,lca[20][20],dep[20],dis[20][20],f[20],ans,x[20],dist;
bool flag[20],in[20];
struct point
{
	int ed,nxt;
}a[40];
void adg(int u,int v)
{
	a[tot].ed=v;
	a[tot].nxt=head[u];
	head[u]=tot++;
}
void getd(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for (int i=head[u];i!=-1;i=a[i].nxt)
	{
		int v=a[i].ed;
		if (v==fa) continue;
		getd(v,u);
	}
}
int getlca(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]>dep[v]) u=f[u];
	if (u==v) return u;
	while (u!=v) u=f[u],v=f[v];
	return u;
}
void getl(int u)
{
	flag[u]=1;
	for (int i=head[u];i!=-1;i=a[i].nxt)
	{
		int v=a[i].ed;
		if (flag[v]) continue;
		if (!in[v]) continue;
		getl(v);
	}
}
bool chk()
{
	for (int i=1;i<=n;i++) flag[i]=0;
	int cnt=0;
	for (int i=1;i<=k;i++)
		if (!flag[x[i]])
		{
			cnt++;
			getl(x[i]);
		}
	if (cnt>2) return 0;
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		int mm=1111;
		for (int j=1;j<=n;j++)
			if (in[j])
				mm=min(mm,dis[i][j]);
		mx=max(mx,mm);
	}
	dist=mx;
	return 1;
}
void dfs(int u,int cnt)
{
	if (u==n+1)
	{
		if (cnt!=k) return;
		
		if (chk())
			ans=min(ans,dist);
		return;
	}
	dfs(u+1,cnt);
	in[u]=1;
	x[cnt+1]=u;
	dfs(u+1,cnt+1);
	in[u]=0;
}
void solve1()
{
	while (t--)
	{
		ans=1e8;
		memset(head,-1,sizeof(head));
		tot=0;
		memset(lca,0,sizeof(lca));
		memset(dep,0,sizeof(dep));
		memset(dis,0,sizeof(dis));
		memset(f,0,sizeof(f));
		cin >> n >> k;
		for (int i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			adg(u,v);
			adg(v,u);
		}
		getd(1,0);
		for (int i=1;i<=n;i++)
			lca[i][i]=i,dis[i][i]=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			{
				lca[i][j]=getlca(i,j);
				dis[i][j]=dis[j][i]=dep[i]+dep[j]-2*dep[lca[i][j]];
			}
		dfs(1,0);
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> ca >> t;
	if (ca<=3) solve1();
	return 0;
}