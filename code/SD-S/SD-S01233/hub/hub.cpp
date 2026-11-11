#include<bits/stdc++.h>
using namespace std;
const int mx=1e6;
int hd[mx+10],E,n,m;
struct noden
{
	int t,nx;
}edg[2*mx+10];
int dep[mx+10],fth[mx+10],lenn[mx+10];
int cx[mx+10],cy[mx+10],ans;
vector<int> gg[mx+10];
pair<int,int> f[mx+10],g[mx+10];
pair<int,int> pre[mx+10],suf[mx+10];
inline int read()
{
	int v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=(v<<1)+(v<<3)+(ch^48);
		ch=getchar();
	}
	return v;
}
void dfs(int u,int ff)
{
	int i,v;
	fth[u]=ff;lenn[u]=1;
	for(i=hd[u];~i;i=edg[i].nx)
	{
		v=edg[i].t;
		if((i>>1)==E||v==ff) continue;
		dep[v]=dep[u]+1;dfs(v,u);
		lenn[u]=max(lenn[u],lenn[v]+1);
	}
	return;
}
void getcnt(int X,int cx[mx+10])
{
	int i,u,d;
	for(i=1;i<=n;++i) dep[i]=-1;
	dep[X]=0;dfs(X,0);
	for(i=1;i<=n;++i)
		if(~dep[i]&&dep[i]>dep[X]) X=i;
	for(i=1;i<=n;++i) dep[i]=-1;
	dep[X]=0;dfs(X,0);u=X;
	for(i=1;i<=n;++i)
		if(~dep[i]&&dep[i]>dep[u]) u=i;
	d=dep[u];
	while(dep[u]!=(d>>1)) u=fth[u];
	for(i=1;i<=n;++i) dep[i]=-1;
	X=u;dep[X]=0;dfs(X,0);
	for(i=1;i<=n;++i) cx[i]=0;
	for(i=1;i<=n;++i)
		if(~dep[i]&&i!=X) cx[lenn[i]]++;
	return;
}
int solv()
{
	int i=n,j=n,ss=2;
	getcnt(edg[E<<1].t,cx);
	getcnt(edg[E<<1|1].t,cy);
	while(i&&j)
	{
		if(ss+cx[i]+cy[j]<=m)
			ss+=cx[i--]+cy[j--];
		else break;
	}
	return max(i,j);
}
pair<int,int> operator +(const pair<int,int>
&aa,const pair<int,int> &bb)
{
	pair<int,int> cc;
	cc.first=max(aa.first,bb.first+1);
	cc.second=max(aa.second,bb.second);
	cc.second=max(cc.second,aa.first
	+bb.first);
	return cc;
}
void prep(int u,int ff)
{
	int i,sz=gg[u].size();
	if(u!=1)
	{
		for(i=0;i<sz;++i)
			if(gg[u][i]==ff) break;
		for(;i<sz-1;++i) gg[u][i]=gg[u][i+1];
		gg[u].pop_back();
	}
	for(int v:gg[u]) prep(v,u);
	return;
}
void dfsa(int u)
{
	f[u]=make_pair(1,1);
	for(int v:gg[u])
	{
		dfsa(v);
		f[u]=f[u]+f[v];
	}
	return;
}
void dfsb(int u)
{
	int i,v,sz=gg[u].size();
	ans=min(ans,max(f[u].second,g[u].second)
	>>1);
	if(!sz) return;
	pre[0]=make_pair(1,1);
	for(i=1;i<sz;++i)
		pre[i]=pre[i-1]+f[gg[u][i-1]];
	suf[sz-1]=make_pair(1,1);
	for(i=sz-2;i>=0;--i)
		suf[i]=suf[i+1]+f[gg[u][i+1]];
	for(i=0;i<sz;++i)
	{
		v=gg[u][i];
		suf[i].first--;
		g[v]=pre[i]+suf[i];
		g[v]=g[v]+g[u];
	}
	for(i=0;i<sz;++i)
	{
		v=gg[u][i];dfsb(v);
	}
	return;
}
int main()
{
	mt19937 myrand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int i,cc,tt,x,y;
	cc=read();tt=read();
	while(tt--)
	{
		n=read();m=read();ans=1e9;
		if(cc<=10)
		{
			for(i=1;i<=n;++i) hd[i]=-1;
			for(i=1;i<n;++i)
			{
				x=read();y=read();
				edg[i<<1].t=y;
				edg[i<<1].nx=hd[x];
				hd[x]=i<<1;
				edg[i<<1|1].t=x;
				edg[i<<1|1].nx=hd[y];
				hd[y]=i<<1|1;
			}
			for(E=1;E<n;++E)
				ans=min(ans,solv());
			printf("%d\n",ans);
		}
		else if(cc<=12)
		{
			for(i=1;i<=n;++i) gg[i].clear();
			for(i=1;i<n;++i)
			{
				x=read();y=read();
				gg[x].push_back(y);
				gg[y].push_back(x);
			}
			prep(1,0);dfsa(1);dfsb(1);
			printf("%d\n",ans);
		}
		else if(cc<=14)
		{
			for(i=1;i<=n;++i) hd[i]=-1;
			for(i=1;i<n;++i)
			{
				x=read();y=read();
				edg[i<<1].t=y;
				edg[i<<1].nx=hd[x];
				hd[x]=i<<1;
				edg[i<<1|1].t=x;
				edg[i<<1|1].nx=hd[y];
				hd[y]=i<<1|1;
			}
			int m=(n-1)>>1;
			E=m+1>>1;printf("%d\n",solv());
		}
		else
		{
			for(i=1;i<=n;++i) hd[i]=-1;
			for(i=1;i<n;++i)
			{
				x=read();y=read();
				edg[i<<1].t=y;
				edg[i<<1].nx=hd[x];
				hd[x]=i<<1;
				edg[i<<1|1].t=x;
				edg[i<<1|1].nx=hd[y];
				hd[y]=i<<1|1;
			}
			for(i=1;i<=10;++i)
			{
				E=myrand()%(n-1)+1;
				ans=min(ans,solv());
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
