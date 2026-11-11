#include<bits/stdc++.h>
using namespace std;
struct bian
{
	int be,en;
	long long val;
}b[10000005];
int c,n,m,d,q,cnt,df;
long long w[500005],t,dis[500505];
int k,a,x,y,s[500505],fa[500505],dp[500505];
vector<pair<int,long long> >z[500505];
long long f[500505][60];
inline long long read()
{
	long long ifff=1,ix=0;
	char c=getchar();
	while('0'>c||c>'9')
	{
		if(c=='-')ifff*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')ix=ix*10+(c-'0'),c=getchar();
	return ifff*ix;
}
void pri(long long ox)
{
	if(ox<0)putchar('-'),ox=-ox;
	if(ox>9)pri(ox/10);
	putchar(ox%10+'0');
	return;
}
bool cmp(bian x,bian y)
{
	return x.val<y.val;
}
int find(int x)
{
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int u,int ff)
{
	dp[u]=dp[ff]+1;
	f[u][0]=ff;
	long long ttt=1;
	while(f[f[u][ttt-1]][ttt-1])f[u][ttt]=f[f[u][ttt-1]][ttt-1],ttt++;
	//cout<<u<<"LCa";
	for(int i=0;i<z[u].size();i++)
	{
		int v=z[u][i].first;
		long long va=z[u][i].second;
		if(v==ff)continue;
		dis[v]=dis[u]+va;
		dfs(v,u);
	}
	return;
}
long long lca(int u,int v)
{
	if(dp[u]>dp[v])swap(u,v);
	//cout<<u<<' '<<v;
	for(int i=20;i>=0;i--)if(dp[f[v][i]]>=dp[u])v=f[v][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)if(f[u][i]!=f[v][i])v=f[v][i],u=f[u][i];
	return f[u][0];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)fa[i]=i,w[i]=read();
	for(int i=1;i<=n;i++)
	{
		fa[m+i]=m+i;
		k=read();
		for(int j=1;j<=k;j++)
		{
			a=read(),t=read();
			b[++cnt].be=m+i;
			b[cnt].en=a;
			b[cnt].val=t;
			//cout<<"BI"<<m+i<<' '<<a<<" "<<t<<'\n';
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=b[i].be,v=b[i].en;
		long long va=b[i].val;
		if(find(u)!=find(v))
		{
			//cout<<u<<' '<<v<<"!!\n";
			fa[find(v)]=fa[find(u)];
			//cout<<find(9)<<' '<<find(2)<<'\n';
			find(v);
			find(u);
			z[u].push_back(make_pair(v,va));
			z[v].push_back(make_pair(u,va));
			/*for(int i=1;i<=n+m;i++)
			{
				cout<<fa[i]<<' ';
			}
			cout<<'\n';*/
		}
	}
	//cout<<"MST";
	dfs(1,0);
	//cout<<"DFS";
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		long long lc=lca(x,y);
		//cout<<lc<<'\n';
		pri(1ll*dis[x]-dis[lc]+dis[y]-dis[lc]+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
