#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>g[N];
int n,kk,mx[N],mx1[N],mx2[N],mx3[N],son[N],son1[N],dep[N],rnk[N],dfn[N],ed[N],cnt,c1[N],rt1[N],c2[N],c4[N],lim;
bool flag;
void dfs1(int u,int fa)
{
	for(int v:g[u])if(v!=fa)
	{
		dep[v]=dep[u]+1;
		dfs1(v,u);
		if(mx[v]+1>mx[u])
		{
			mx1[u]=mx[u];
			son1[u]=son[u];
			mx[u]=mx[v]+1;
			son[u]=v;
		}
		else if(mx[v]+1>mx1[u])
		{
			mx2[u]=mx1[u];
			mx1[u]=mx[v]+1;
			son1[u]=v;
		}
		else mx2[u]=max(mx2[u],mx[v]+1);
	}
}
void dfs2(int u,int fa)
{
	cnt++;
	dfn[u]=cnt;
	rnk[cnt]=u;
	if(son[u])
	{
		mx3[son[u]]=max(mx3[u]+1,mx1[u]);
		dfs2(son[u],u);
	}
	for(int v:g[u])if(v!=fa&&v!=son[u])
	{
		mx3[v]=max(mx3[u]+1,mx[u]);
		dfs2(v,u);
	}
	ed[u]=cnt;
}
void dfs3(int u,int fa)
{
	c1[u]=mx[u]>=lim;
	for(int v:g[u])if(v!=fa)
	{
		c4[v]=c4[u]+(mx[u]<lim);
		dfs3(v,u);
		c1[u]+=c1[v];
	}
	if(mx1[u]>=lim||!son[u])
	{
		rt1[u]=u;
		c2[u]=c1[u];
	}
	else
	{
		rt1[u]=rt1[son[u]];
		if(dep[rt1[u]]-dep[u]+mx1[u]>lim)
		{
			rt1[u]=rnk[dfn[u]+min(lim-mx1[u],mx[u])];
		}
		c2[u]=max(1,c1[rt1[u]]);
	}
}
void dfs4(int u,int fa,int d1,int d2,int l1,int l2,int l3)
{
	/*
	int rt2;
	if(d1>d3)
	{
		if(max(d3,d2)>=lim)rt2=1;
		else if(max(d3,d2)+dep[rt1[l2]]<=lim)rt2=rt1[l2];
		else rt2=rnk[dfn[l2]+min(mx[l2],lim-max(d2,d3)-1)];
	}
	else
	{
		if(d1>=lim)rt2=1;
		else if(dep[l1]+d1>=lim)rt2=rnk[1+lim-d1];
		else if(!l2)rt2=l1;
		else rt2=rnk[dfn[l2]+min(mx[l2],lim-d1-dep[l1]-1)];
	}
	int c3=0;
	if(dfn[u]>=dfn[rt2]&&dfn[u]<=ed[rt2])
	{
		c3=c4+max(0,dep[u]-l3);
	}
	else
	{
		c3=c1[rt2];
	}
	*/
	int rt2=0,c3=0;
	if(!l2||d2>=lim)
	{
		rt2=rt1[1];
		if(dep[rt2]>dep[l1])rt2=l1;
		c3=c1[rt2]-c1[u]-max(0,dep[u]-dep[rt2]-c4[u])+max(0,dep[u]-dep[rt2]-l3);
	}
	else
	{
		rt2=rt1[l2];
		if(dep[rt2]-dep[l1]+d2>lim)
		{
			rt2=rnk[dfn[l2]+min(mx[l2],lim-d2-1)];
		}
		c3=c1[rt2];
	}
	if(c2[u]+max(1,c3)<=kk)
	{
		flag=1;
		return;
	}
	for(int v:g[u])if(v!=fa)
	{
		int d4=0;
		if(v==son[u])d4=mx1[u];
		else d4=mx[u];
		int nd1=max(d1,d4+dep[u]);
		int nl1=l1,nl2=l2,nd2=0;
		if(nd1>d1)
		{
			nl1=u;
			if(v==son[u])nl2=son1[u];
			else nl2=son[u];
			nd2=mx3[u]+1;
			if(v==son[u]||v==son1[u])nd2=max(nd2,mx2[u]);
			else nd2=max(nd2,mx1[u]);
		}
		else
		{
			nd2=max(d2,d4+dep[u]-dep[l1]);
		}
		int nl3=l3+1;
		nl3=min(nl3,max(0,lim-d4));
		dfs4(v,u,nd1,nd2,nl1,nl2,nl3);
		if(flag)return;
	}
}
bool chk(int x)
{
	flag=0;
	lim=x;
	for(int i=0;i<=n;i++)c1[i]=rt1[i]=c2[i]=c4[i]=0;
	dfs3(1,0);
	if(c1[1]<=kk)return 1;
	for(int v:g[1])
	{
		int d1,d2,l2;
		if(v==son[1])
		{
			d1=mx1[1],d2=mx2[1],l2=son1[1];
		}
		else if(v==son1[1])
		{
			d1=mx[1],d2=mx2[1],l2=son[1];
		}
		else
		{
			d1=mx1[1],d2=mx1[1],l2=son[1];
		}
		dfs4(v,1,d1,d2,1,l2,max(0,lim-d1));
	}
	return flag;
}
void solve()
{
	cin>>n>>kk;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=0;i<=n;i++)
	{
		mx[i]=mx1[i]=son[i]=son1[i]=dep[i]=mx3[i]=mx2[i]=0;
		rnk[i]=dfn[i]=ed[i]=0;
	}
	cnt=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int cid,T;
	cin>>cid>>T;
	while(T--)solve();
}
