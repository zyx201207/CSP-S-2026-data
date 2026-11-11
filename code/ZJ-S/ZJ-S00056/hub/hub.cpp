#include<bits/stdc++.h>
#define int long long

const int N=35;

using namespace std;

int cid,T;

int n,k,ans;

vector<int>e[N];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

void add_e(int x,int y){
	e[x].push_back(y);
}

int vis[N];

int fa[N];

namespace HLD{
	struct node{
		int dep,siz,fa,hson,top,dfn;
	}a[N];
	int tim,rnk[N];
	void _init(){
		for(int i=1;i<=n;i++)a[i]=(node){0,0,0,0,0,0},rnk[i]=0;
		tim=0;
	}
	void dfs1(int u,int dep){
		a[u].dep=dep;
		a[u].siz=1;
		int siz=e[u].size();
		for(int i=0;i<siz;i++){
			int v=e[u][i];
			if(v==a[u].fa)continue;
			a[v].fa=u;
			dfs1(v,dep+1);
			a[u].siz+=a[v].siz;
			if(a[v].siz>a[a[u].hson].siz)a[u].hson=v;
		}
	}
	void dfs2(int u,int top){
		a[u].top=top;
		a[u].dfn=++tim;
		rnk[tim]=u;
		if(a[u].hson){
			dfs2(a[u].hson,top);
			int siz=e[u].size();
			for(int i=0;i<siz;i++){
				int v=e[u][i];
				if(v==a[u].fa||v==a[u].hson)continue;
				dfs2(v,v);
			}
		}
	}
	int lca(int u,int v){
		while(a[u].top!=a[v].top){
			if(a[a[u].top].dep<a[a[v].top].dep)swap(u,v);
			u=a[a[u].top].fa;
		}
		if(a[u].dep>a[v].dep)swap(u,v);
		return u;
	}
}

void _init(){
	ans=1e18;
	HLD::_init();
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)e[i].clear();
}

int getfa(int x){
	return (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}

void _uni(int x,int y){
	int fx=getfa(x),fy=getfa(y);
	fa[fx]=fy;
}

int dis(int u,int v){
	int p=HLD::lca(u,v);
	return (HLD::a[u].dep)+(HLD::a[v].dep)-(HLD::a[p].dep)*2;
}

void _calc(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		int siz=e[i].size();
		for(int k=0;k<siz;k++){
			int j=e[i][k];
			if(!vis[j])continue;
			_uni(i,j);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		if(fa[i]==i)cnt++;
	}
	if(cnt!=2)return;
	int mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		int tt=1e9;
		for(int j=1;j<=n;j++){
			if(!vis[j])continue;
			tt=min(tt,dis(i,j));
		}
		mx=max(mx,tt);
	}
	ans=min(ans,mx);
}

void dfs(int now,int stp){
	if(stp>k){
		_calc();
		return;
	}
	for(int i=now;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(i,stp+1);
		vis[i]=0;
	}
}

void _solve(){
	n=read(),k=read();
	_init();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add_e(u,v),add_e(v,u);
	}
	HLD::dfs1(1,0),HLD::dfs2(1,1);
	dfs(1,1);
	printf("%lld\n",ans);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=read(),T=read();
	while(T--)_solve();
	return 0;
}

/*

0 1
5 3
1 2
2 3
3 4
4 5

This is Rigel, luogu 602458.

( My Engligh is really poor. qwq )

I am a grade-12 student. Yes, senior-high-3.

Only 1 month after NOIP2026, I will take part in ZJ Shoukao, a part of Gaokao.

This contest, CSP-S 2026, is my last CSP.

If there's no issues in my code, my score will be:

100 + 100 + 24 + 5 = 229 pts.

Why T2 so easy. So I think level-7 line on luogu will be around my score, +- 10 pts.

Good luck.

*/