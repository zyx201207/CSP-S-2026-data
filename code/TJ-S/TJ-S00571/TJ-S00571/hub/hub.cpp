#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<string>
template<typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template<typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

int n,k;

namespace Force{
	const int N = 15,M = 2*N,INF = 0x3f3f3f3f;
	bool graph[N][N];
	int dist[N][N];
	bool f[N];
	int chosen[N];
	int p[N];
	int find(int x){return p[x]!=x?p[x]=find(p[x]):x;}

	bool valid(){
		for(int i=1;i<=k;i++) p[chosen[i]] = chosen[i];
		for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) if(graph[chosen[i]][chosen[j]]) p[find(chosen[i])] = find(chosen[j]);
		int res = 0;
		for(int i=1;i<=k;i++) if(p[chosen[i]]==chosen[i]) res++;
		return res<=2;
	}
	void solve(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) graph[i][j] = false;
		for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),graph[u][v] = graph[v][u] = true;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j] = i==j?0:(graph[i][j]?1:INF);
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tense(dist[i][j],dist[i][k]+dist[k][j]);
		
		for(int i=1;i<=n;i++) f[i] = i<=k;
		std::sort(f+1,f+n+1);
		int ans = INF;
		do{
			int len = 0;
			for(int i=1;i<=n;i++) if(f[i]) chosen[++len] = i;
			if(valid()){
				int res = 0;
				for(int i=1;i<=n;i++){
					int d = INF;
					for(int j=1;j<=k;j++) tense(d,dist[i][chosen[j]]);
					relax(res,d);
				}
				tense(ans,res);
			}
		} while(std::next_permutation(f+1,f+n+1));
		printf("%d\n",ans);
	}
}
namespace Better{
	const int N = 1e5+10,M = 2*N;
	int h[N],e[M],ne[M],idx;
	int fa[N],depth[N],size[N];
	int son[N],top[N],dfnl[N],dfnr[N],timestamp;
	void add(int u,int v){
		e[++idx] = v,ne[idx] = h[u],h[u] = idx;
	}

	void setup(int u){
		size[u] = 1,son[u] = 0;
		for(int i=h[u];i;i=ne[i]){
			int v = e[i];
			if(v==fa[u]) continue;
			fa[v] = u;
			depth[v] = depth[u]+1;
			setup(v);
			size[u]+=size[v];
			if(!son[u]||size[v]>size[son[u]]) son[u] = v;
		}
	}
	void getdfn(int u){
		dfnl[u] = ++timestamp;
		if(son[u]) top[son[u]] = top[u],getdfn(son[u]);
		for(int i=h[u];i;i=ne[i]){
			int v = e[i];
			if(v==fa[u]||v==son[u]) continue;
			top[v] = v,getdfn(v);
		}
		dfnr[u] = timestamp;
	}
	void solve(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) h[i] = 0;
		idx = 0;
		for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
		int root = 1;
		fa[root] = 0,depth[root] = 1,setup(root);
		timestamp = 0,top[root] = root,getdfn(root);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		Force::solve();
	}
	return 0;
}


