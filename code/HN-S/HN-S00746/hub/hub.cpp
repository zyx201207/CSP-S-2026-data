#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
#define double long double
#define unsigned unsigned int
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
int t,n,k,now,ans,a[1000005],pra[1000005],dep[1000005],fa[1000005][25];
bool vis[1000005];vector<int>e[1000005];set<int>st;
int read()
{
	int x=0,op=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*op;
}
void write(int x)
{
	if(x<0)
	{
		x*=-1;
		putchar('-');
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
	return;
}
void dfs1(int u,int father)
{
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u])
		if(v!=father)
			dfs1(v,u);
	return;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int getfa(int x)
{
	if(pra[x]==x)return x;
	pra[x]=getfa(pra[x]);
	return pra[x];
}
bool check()
{
	st.clear();
	for(int i=1;i<=n;i++)
		pra[i]=i;
	for(int i=1;i<=k;i++)
		for(auto v:e[a[i]])
			if(vis[v]==1)
				pra[getfa(a[i])]=pra[getfa(v)];
	for(int i=1;i<=k;i++)
		st.insert(pra[a[i]]);
	return st.size()==2;
}
int getcnt()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		int res=2e18;
		for(int j=1;j<=k;j++)
		{
			int it=lca(i,a[j]);
			int dis=dep[i]+dep[a[j]];
			res=min(res,dis-2*dep[it]);
		}
		cnt=max(cnt,res);
	}
	return cnt;
}
void dfs2(int it,int num)
{
	if(num==k)
	{
		if(!check())
			return;
		ans=min(ans,getcnt());
		return;
	}
	if(it==n+1)
		return;
	vis[it]=1;
	a[num+1]=it;
	dfs2(it+1,num+1);
	vis[it]=0;
	dfs2(it+1,num);
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	now=read(),t=read();
	while(t--)
	{
		n=read(),k=read();
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=2e18;
		dfs1(1,0);
		dfs2(1,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}
