#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1e6+9;
int n,k,fa[N],now,dis[1009][1009];
vector<int> g[N],node;
bool F=0;

int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int get_dis(int u,int from,int t) {
	if(u==t) {
		F=1;
		return now;
	}
	for(int v:g[u]) {
		if(v==from) continue;
		now++;
		get_dis(v,u,t);
		if(F) return now;
		now--;
	}
}

void solve() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) g[i].clear();	
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			dis[i][j]=get_dis(i,i,j);
			dis[j][i]=dis[i][j];
		}
	}
	int ans=1e9+7;
	for(int state=0;state<(1<<n);state++) {
		node.clear();
		int h=0;
		for(int i=0;i<n;i++) fa[i]=i;
		for(int i=0;i<n;i++) if(state&(1<<i)) h++,node.push_back(i);
		if(h!=k) continue;
		for(int i=0;i<n;i++) {
			if(!(state&(1<<i))) continue;
			int fa_i=find(i);
			for(int v:g[i]) {
				if(!(state&(1<<v))) continue;
				int fa_v=find(v);
				if(fa_v!=fa_i) fa[fa_v]=fa_i;
			}
		}
		sort(fa,fa+n);
		int cnt=0,siz=1;
		for(int i=1;i<n;i++) {
			if(fa[i]!=fa[i-1]) {
				if(siz>1) cnt++;
				siz=1;
			} else siz++;
		}
		if(cnt<=2) {
			int max_dis=-1;
			for(int cur:node) {
				for(int nxt:node) {
					if(cur==nxt) continue;
					now=0; F=0;
					max_dis=max(max_dis,dis[cur][nxt]);
				}
			}
			ans=min(ans,max_dis);
		}
	}
	printf("%d\n",ans);
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}