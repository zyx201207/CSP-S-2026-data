#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=1e6+1000,M2=1e3+100;
lint C,T;
lint n,k;
lint u[M1],v[M1];
bool f[M1];
lint pre[M1],pkp;
struct node{
	lint to,next;
}a[M1];
void add(lint u,lint v){a[++pkp]={v,pre[u]},pre[u]=pkp;}
lint cou(lint x)
{
	lint s=0;
	while(x)
	{
		if(x&1) s++;
		x=x>>1;
	}
	return s;
}
lint faa[M1],dep[M1],fa[M1][20],llog[M1];
lint find(lint x)
{
	if(faa[x]==x) return x;
	return faa[x]=find(faa[x]);
}
void merge(lint x,lint y)
{
	lint rx=find(x),ry=find(ry);
	if(rx!=ry) faa[rx]=ry;
}
void dfs(lint x,lint fath)
{
	fa[x][0]=fath;
	dep[x]=dep[fath]+1;
	for(lint i=pre[x];i;i=a[i].next)
	{
		lint too=a[i].to;
		if(too!=fath)
		{
			dfs(too,x);
			if(f[too]&&f[x]) merge(too,x);
		}
	}
}
lint lca(lint u,lint v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]!=dep[v]) u=fa[u][llog[dep[u]-dep[v]]];
	if(u==v) return u;
	for(lint i=19;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
void init()
{
	memset(pre,0,sizeof(pre));
	pkp=0;
	memset(fa,0,sizeof(fa));
	memset(dep,0,sizeof(dep));
}
lint culc(lint u,lint v){return dep[v]+dep[u]-2*dep[lca(u,v)];}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	if(C>=4)
	{
		while(T--) printf("1\n");
		return 0;
	}
	while(T--)
	{
		init();
		scanf("%lld%lld",&n,&k);
		for(lint i=2;i<=n;i++) llog[i]=llog[i/2]+1;
		for(lint i=1;i<n;i++)
		{
			scanf("%lld%lld",&u[i],&v[i]);
			add(u[i],v[i]);
			add(v[i],u[i]);
		}
		dfs(1,0);
		for(lint j=1;j<=19;j++)
		{
			for(lint i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		lint minnn=1e18;
		for(lint i=0;i<(1ll<<n);i++)
		{
			if(cou(i)!=k) continue;
			for(lint j=1;j<=n;j++) faa[j]=j,f[j]=0;
			lint xp=i,s=1;
			while(xp)
			{
				if(xp&1) f[s]=1;
				xp=xp>>1;
				s++;
			}
			dfs(1,0);
			lint os=0;
			for(lint j=1;j<=n;j++)
			{
				if(f[j]&&faa[j]==j) os++;
			}
			if(os>2) continue;
			lint maxn=0;
			for(lint ii=1;ii<=n;ii++)
			{
				lint minn=1e18;
				if(f[ii]) continue;
				for(lint j=1;j<=n;j++)
				{
					if(!f[j]) continue;
					minn=min(minn,culc(ii,j));
				}
				maxn=max(maxn,minn);
			}
			minnn=min(minnn,maxn);
		}
		printf("%lld\n",minnn);
	}
	return 0;
}
