#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
inline int read(){
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
inline void chkmax(int &a,int b){a=max(a,b);}
inline void chkmin(int &a,int b){a=min(a,b);}
const int N=1e6+5,M=2*N;
const int inf=2e18;
int n,k;
int h[N],e[M],ne[M],idx;
inline void add(int a,int b){e[++idx]=b,ne[idx]=h[a],h[a]=idx;}
int col[20],dist[15][15];
void dfs1(int u,int co,int sta){
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];
		if(!col[v]&&(sta&(1<<v-1))){
			col[v]=co;
			dfs1(v,co,sta);
		}
	}
}
void work1(){
	int ans=inf;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dist[i][j]=i==j?0:inf;
	for(int i=1;i<=n;++i){
		for(int j=h[i];j;j=ne[j]){
			dist[i][e[j]]=1;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				chkmin(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0;i<=1<<n;++i){
		for(int j=1;j<=n;++j)col[j]=0;
		int tot=0;
		for(int j=1;j<=n;++j){
			if(i&(1<<j-1))++tot;
		}
		if(tot!=k)continue;
		int ar=0;
		for(int j=1;j<=n;++j){
			if(i&(1<<j-1)){
				if(!col[j]){
					col[j]=++ar;
					dfs1(j,col[j],i);
				}
			}
		}
		if(ar>2)continue;
		int now=0;
		for(int j=1;j<=n;++j){
			int pt=inf;
			for(int k=1;k<=n;++k){
				if(i&(1<<k-1))chkmin(pt,dist[j][k]);
			}
			chkmax(now,pt);
		}
		chkmin(ans,now);
	}
	printf("%lld\n",ans);
}
int fa[N][20],dep[N],dfn[N],now;
int a[N],cnt;
void dfs(int u,int dad){
	dep[u]=dep[dad]+1;fa[u][0]=dad;dfn[u]=++now;
	for(int i=1;i<20;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=h[u];i;i=ne[i]){
		int v=e[i];if(v==dad)continue;
		dfs(v,u);
	}
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=19;i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs2(int u,int dad){
	
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
bool check(int dis){
	dfs2(1,0);
	cnt=0;
	sort(a+1,a+cnt+1,cmp);
	a[++cnt]=a[1];
	int ans=0,res;
	for(int i=2;i<=cnt;++i){
		int lca=LCA(a[i],a[i-1]);
		ans+=dep[a[i]]-dep[lca]+dep[a[i-1]]-dep[lca];
	}ans/=2,res=ans;
	for(int i=1;i<cnt;++i){
		int tot=ans;
		int l1=LCA(a[1],a[i]),l2=LCA(a[i+1],a[cnt-1]);
		tot+=dep[a[1]]-dep[l1]+dep[a[i]]-dep[l1];
		tot+=dep[a[i+1]]-dep[l2]+dep[a[cnt-1]]-dep[l2];
		int l3=LCA(a[1],a[cnt-1]),l4=LCA(a[i],a[i+1]);
		tot-=dep[a[1]]-dep[l3]+dep[a[cnt-1]]-dep[l3];
		tot-=dep[a[i]]-dep[l4]+dep[a[i+1]]-dep[l4];
		chkmin(res,tot);
	}
	int rl=res/2+1;
	return rl<=k;
}
void work2(){
	dfs(1,0);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			add(u,v),add(v,u);
		}
		if(n<=10)work1();
		else work2();
		for(int i=1;i<=n;++i)h[i]=0;
		idx=0;
	}
	return 0;
}

