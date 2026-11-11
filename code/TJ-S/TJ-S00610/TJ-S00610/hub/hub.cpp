#include <cstdio>
const int N=100010,E=N<<1;
int n,k;
int e,to[E],next[E],head[N];
void add_edge(int u,int v){to[++e]=v,next[e]=head[u],head[u]=e;}
bool vis[N];
namespace DFS {
	void dfs(int x) {
		size[x]=1;
		for (int i=head[x];i;i=next[i]) if (to[i]!=fa[x]) {
			fa[to[i]]=x;
			dep[to[i]]=dep[x]+1;
			dfs(to[i]);
			size[x]+=size[to[i]];
		}
	}
}
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool merge(int u,int v) {
	u=find(u),v=find(v);
	if (u==v) return false;
	fa[u]=v;
}
bool cnt[N];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while (T--) {
		int n;
		scanf("%d%d",&n,&k);
		for (int i=0;i<(1<<n);i++) if (__builtin_popcount(i)==k) {
			for (int j=0;j<n;j++) if (i>>j&1) {
				vis[j+1]=true;
			}
			for (int j=1;j<=n;j++) fa[j]=j;
			for (int j=1;j<=n;j++) if (vis[j]) {
				for (int k=head[j];k;k=next[k]) merge(j,to[k]);
			}
			for (int j=1;j<=n;j++) if (vis[j]) {
				cnt[fa[j]]=true;
			}
			int colors=0;
			for (int j=1;j<=n;j++) colors+=cnt[j];
			if (colors==2) {
				
			}
		}
		
	}
	return 0;
}
