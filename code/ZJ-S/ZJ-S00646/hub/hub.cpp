#include<bits/stdc++.h>
using namespace std;namespace hxyt1{
//#define int ll
#define ll long long
#define U unsigned
#define file(s) freopen(#s ".in","r",stdin),freopen(#s ".out","w",stdout)
#define rad read<int>
#define gc getchar
template<class T>T read(){char c;bool f=0;T x=0;for(;!isdigit(c=gc());f|=c=='-');for(;isdigit(c);x=x*10+c-48,c=gc());return f?-x:x;}
const int N=1e6+5;int n,k,lnk[N],son[N<<1],nxt[N<<1],tot,stlca[20][N],dfn[N],tim,siz[N],fa[N],dep[N],ans;bool vis[N],vis1[N];
void add(int x,int y){nxt[++tot]=lnk[x];son[lnk[x]=tot]=y;}
#define get(u,v) (dfn[u]<dfn[v]?u:v)
void plca(int u,int fa){
	stlca[0][dfn[u]=++tim]=fa;
	for(int i=lnk[u];i;i=nxt[i]){
		int v=son[i];
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		plca(v,u);
	}
}
int lca(int u,int v){
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))swap(u,v);
	int x=__lg(v-u++);
	return get(stlca[x][u],stlca[x][v-(1<<x)+1]);
}
int gf(int u){return fa[u]==u?u:fa[u]=gf(fa[u]);}
void mrg(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return;
	if(siz[x]>siz[y])fa[y]=x;
	else fa[x]=y;
}
void dfs(int x,int cnt){
	if(cnt==k){
		memset(vis1,0,sizeof vis1);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int u=1;u<=n;u++)if(vis[u])for(int i=lnk[u];i;i=nxt[i]){
			int v=son[i];
			if(vis[v])mrg(u,v);
		}
		int cn=0;
		for(int i=1;i<=n;i++)if(vis[i])cn+=!vis1[gf(i)],vis1[gf(i)]=1;
		if(cn>2)return;
		cn=0;
		for(int u=1;u<=n;u++){
			int di=INT_MAX;
			for(int v=1;v<=n;v++)if(vis[v])di=min(di,dep[u]+dep[v]-(2*dep[lca(u,v)]));
			cn=max(cn,di);
		}
		ans=min(ans,cn);
	}
	for(int i=x+1;i<=n;i++)vis[i]=1,dfs(i,cnt+1),vis[i]=0;
}
void hxyt(){
	file(hub);
	rad();for(int _=rad();_--;){
		memset(lnk,0,sizeof lnk);tot=0;ans=INT_MAX;
		memset(siz,0,sizeof siz);tim=0;
		memset(son,0,sizeof son);
		memset(nxt,0,sizeof nxt);
		memset(stlca,0,sizeof stlca);
		memset(dfn,0,sizeof dfn);
		memset(dep,0,sizeof dep);
		n=rad(),k=rad();
		for(int i=1,u,v;i<n;i++)u=rad(),v=rad(),add(u,v),add(v,u);
		plca(1,0);
		for(int i=1;i<=__lg(n);i++)for(int j=1;j+(1<<i)-1<=n;j++)stlca[i][j]=get(stlca[i-1][j],stlca[i-1][j+(1<<(i-1))]);
		dfs(0,0);
		printf("%d\n",ans);
	}
}}signed main(){return hxyt1::hxyt(),0;}
