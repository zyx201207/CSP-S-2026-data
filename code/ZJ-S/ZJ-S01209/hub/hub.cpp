#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,t,i,j,n,k,T,x,tot,y,ans;
int dfn[maxn],dep[maxn],fa[maxn],cmw[maxn],anc[maxn][21];
vector<int>ve[maxn];
void dfs(int u,int fa)
{
	tot++;
	dfn[u]=tot;
	for(auto v:ve[u])
	{
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		anc[v][0]=u;
		dfs(v,u);
	}
	return;
}
void init()
{
	for(int it=1;it<=20;it++)
	{
		for(int h=1;h<=n;h++)
		{
			anc[h][it]=anc[anc[h][it-1]][it-1];
		}
	}
	return;
}
int fi(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=fi(fa[x]);
}
void hb(int p,int q)
{
	int p1=fi(p),q1=fi(q);
	fa[p1]=q1;
	return;
}
int LCA(int u,int v)
{
	if(dep[u]>dep[v])
	{
		int tmp=u;
		u=v,v=tmp;
	}//dep[u]<=dep[v]
	for(int it=20;it>=0;it--) if(dep[anc[v][it]]>=dep[u]) v=anc[v][it];
	if(u==v) return u;
	for(int it=20;it>=0;it--) if(anc[u][it]!=anc[v][it]) u=anc[u][it],v=anc[v][it];
	return anc[u][0];
}
bool check()
{
	for(int h=1;h<=n;h++) fa[i]=i;
	for(int h=1;h<=n;h++)
	{
		if(cmw[h]==2) continue;
		for(auto asz:ve[h])
		{
			if(cmw[asz]==1) hb(asz,h);
		}
	}
	int s1=0,s2,s3=0;
	for(int h=1;h<=n;h++)
	{
		if(cmw[h]==2) continue;
		if(cmw[h]==1 && !s1) s1=1,s2=fa[h];
		else if(s1 && s2!=fa[h] && s3==0) s3=fa[h];
		else if(s3!=0 && s1!=0 && s2!=fa[h] && s3!=fa[h]) return false;
	}
	return true;
}
int csp()
{
	int rt=0;
	for(int h=1;h<=n;h++)
	{
		int k=11451419;
		for(int yh=1;yh<=n;yh++)
		{
			if(cmw[yh]==1) continue;
			int ddz=LCA(yh,h),g;
			g=dep[yh]+dep[h]-2*dep[ddz];
			k=min(k,g);
		}
		rt=max(rt,k);
	}
	return rt;
}
int noip(int x,int y)
{
	int rt=0;
	for(int h=1;h<=n;h++)
	{
		int k=11451419;
		for(int yh=1;yh<=n;yh++)
		{
			if(yh!=x && yh!=y) continue;
			int ddz=LCA(yh,h),g;
			g=dep[yh]+dep[h]-2*dep[ddz];
			k=min(k,g);
		}
		rt=max(rt,k);
	}
	return rt;
}
void dfch(int p,int l)
{
	if(l>k) return;
	if((n-p+1)+l<k) return;
	if(p==n+1)
	{
		if(check() && l==k)
		{
			int kc=csp();
			ans=min(ans,kc);
		}
		return;
	}
	cmw[p]=1;//in S
	dfch(p+1,l+1);
	cmw[p]=2;
	dfch(p+1,l);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		ans=20101023;
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++) ve[i].clear();
		for(i=1;i<=n-1;i++)
		{
			scanf("%d %d",&x,&y);
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		anc[1][0]=0,dep[1]=1;
		dfs(1,0);
		init();
		if(k==2)
		{
			for(i=1;i<=n;i++)
			{
				cmw[i]=1,cmw[i-1]=2;
				for(j=i+1;j<=n;j++)
				{
					cmw[j-1]=2;
					cmw[j]=1;
					ans=min(ans,noip(i,j));
				}
				cmw[n]=2;
			}
		}
		else if(c<=3) dfch(1,0);
		else ans=rand();
		printf("%lld\n",ans);
	}
	return 0;
}
//Oct31==Dec25?
//luogu uid:562443
//My fifth CSP
//Not for anyone,just for me.
//;;
//freopen y1 genshin
//数据删除 查无此人
//Oct31==Dec25?
//16岁!
//Asz->XJ OIer->MOer
//for my love.
//该怎么说再见呢
//又是遗憾吧
//我们后会有期.
//thank you
//not the end
//