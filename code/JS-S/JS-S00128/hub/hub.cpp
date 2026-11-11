#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
const int N=1e6+5;
int c,T;
int n,k;
vector <int> e[N];
int rt;
int fa[N],dep[N],ht[N],siz[N],son[N],top[N];
void dfs1(int u,int pr){
	fa[u]=pr;
	dep[u]=dep[pr]+1;
	siz[u]=1;
	son[u]=0;
	ht[u]=0;
	for(int v:e[u]) if(v!=pr){
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
		ht[u]=max(ht[u],ht[v]+1);
	}
}
void dfs2(int u,int tp){
	top[u]=tp;
	for(int v:e[u]) if(v!=fa[u]) dfs2(v,v==son[u]?tp:v);
}
int lca(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]]) if(dep[top[u]]<dep[top[v]]) swap(u,v);
	return dep[u]<dep[v]?u:v;
}
int fi[N],se[N],th[N],up[N];
void pre1(int u){
	fi[u]=se[u]=th[u]=0;
	for(int v:e[u]) if(v!=fa[u]){
		pre1(v);
		int x=ht[v]+1;
		if(x>fi[u]) th[u]=se[u],se[u]=fi[u],fi[u]=x;
		else if(x>se[u]) th[u]=se[u],se[u]=x;
		else if(x>th[u]) th[u]=x; 
	}
}
void pre2(int u){
	int f=fa[u];
	if(u!=rt) up[u]=max(up[f],(ht[u]+1==fi[f])?se[f]:fi[f])+1;
	else up[u]=0;
	for(int v:e[u]) if(v!=f) pre2(v);
}
const int M=1005;
int f[M][M],g[M];
int sz[M];
int in[M],out[M],dfn;
void calc(int u){
	rep(i,0,k) f[u][i]=n;
	f[u][0]=ht[u]+1;
	f[u][1]=0;
	sz[u]=1;
	in[u]=++dfn;
	for(int v:e[u]) if(v!=fa[u]){
		calc(v);
		rep(i,1,min(k,sz[u]+sz[v])) g[i]=n;
		rep(x,1,sz[u]) rep(y,0,min(sz[v],k-x)) g[x+y]=min(g[x+y],max(f[u][x],f[v][y]));
		sz[u]+=sz[v];
		rep(x,1,min(k,sz[u])) f[u][x]=g[x];
	}
	rep(i,1,k) f[u][i]=min(f[u][i],f[u][i-1]);
	out[u]=dfn;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		rep(u,1,n) e[u].clear();
		for(int u,v,i=1;i<n;++i){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0);
		rep(u,1,n) if(n-siz[u]<=n/2&&siz[son[u]]<=n/2) rt=u;
		dfs1(rt,0);
		dfs2(rt,rt);
		pre1(rt);
		pre2(rt);
		dfn=0;
		calc(rt);
		int ans=n;
		rep(u,1,n) rep(v,u+1,n){
			int x=lca(u,v);
			int xu=(u!=x)?ht[u]+dep[u]-dep[x]:0,xv=(v!=x)?ht[v]+dep[v]-dep[x]:0;
			if(xu<xv) swap(xu,xv);
			int res=max(up[x],xu==fi[x]?xv==se[x]?th[x]:se[x]:fi[x])+min(dep[u]-dep[x],dep[v]-dep[x]);
			if(u!=x) for(int y=fa[u];y!=x;y=fa[y]){
				int val=ht[u]+dep[u]-dep[y];
				int vl=val==fi[y]?se[y]:fi[y];
				res=max(res,min(vl+dep[u]-dep[y],vl+dep[y]+dep[v]-2*dep[x]));
			}
			if(v!=x) for(int y=fa[v];y!=x;y=fa[y]){
				int val=ht[v]+dep[v]-dep[y];
				int vl=val==fi[y]?se[y]:fi[y];
				res=max(res,min(vl+dep[v]-dep[y],vl+dep[y]+dep[u]-2*dep[x]));
			}
			rep(i,1,k-1) ans=min(ans,max({res,f[u][i],f[v][k-i]}));
		}
		rep(u,1,n) ans=min(ans,max(f[u][k],up[u]));
		cout<<ans<<'\n';
	}
	return 0;
}
