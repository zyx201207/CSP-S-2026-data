#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int read()
{
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int N=1e3+5;
int n,m,val,f[N],g[N];
int F[N][N],G[N][N];
vector<int> e[N];
void dfs(int rt,int u,int fa,int d)
{
	F[rt][u]=fa,G[rt][u]=d;
	for(auto it=e[u].begin();it!=e[u].end();it++)
	{
		int v=*it;
		if(v==fa) continue;
		dfs(rt,v,u,d+1);
	}
}
int dep[N];
void dfs2(int u,int fa)
{
	g[u]=0;
	dep[u]=0,f[u]=1;
	for(auto it=e[u].begin();it!=e[u].end();it++)
	{
		int v=*it;
		if(v==fa) continue;
		dfs2(v,u);
		if(dep[v]+1>val) f[u]+=f[v];
		dep[u]=max(dep[u],dep[v]+1);
	}
}
bool check()
{
	for(int i=1;i<=n;i++) dfs(i,i,0,0);
	for(int i=1;i<=n;i++)
	{
		dfs2(i,0);
		if(f[i]<=m) return true;
		
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=n;k++) g[k]=min(G[i][k],G[j][k]);
			dfs2(i,F[j][i]),dfs2(j,F[i][j]);
			
			int mx=0;
			for(int k=1;k<=n;k++) mx=max(mx,g[k]);
			if(f[i]+f[j]<=m&&mx<=val) return true;
		}
	}
	return false;
}
int main()
{
//	freopen("hub3.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _,T;
	_=read(),T=read();
	while(T--)
	{
		n=read(),m=read();
		//if(n>1e3) cout<<'*';
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		//val=17;
		//cout<<'*'<<check()<<endl;
		int l=0,r=n,ans=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			val=mid;
			if(check()) ans=mid,r=mid-1;
			else l=mid+1;
		}
		print(ans),putchar('\n');
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/