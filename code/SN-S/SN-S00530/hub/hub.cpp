//吴禹泽 SN-S00530 陕西延安中学
#include <iostream>
#include <cstring>
#include <bitset>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define popcnt(x) __builtin_popcount(x)
#define MIKU 0
using namespace std;

struct Edge { int v, nxt; } T[25];
int h[15], tot;
void addE(int u, int v) { T[tot] = {v, h[u]}; h[u] = tot ++; }

const int inf = 0x3f3f3f3f;
int c, t, n, k, ans = inf;
int vis[15], dis[15];

void dfs(int u, int fa, int s) {
	vis[u] = 1;
	for(int e=h[u]; ~e; e=T[e].nxt) {
		int v = T[e].v;
		if(v == fa) continue;
		if(!((s>>(v-1))&1)) continue;
		dfs(v, u, s);
	}
}

bool check(int s) {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for(int i=0; i<n; i++) if((s>>i) & 1) {
		if(!vis[i+1]) {
			cnt++;
			dfs(i+1, 0, s);
		}
	}
	return cnt <= 2;
}

void dfs1(int u, int fa, int s) {
	dis[u] = inf;
	if((s>>(u-1)) & 1) { dis[u] = 0; return; }
	for(int e=h[u]; ~e; e=T[e].nxt) {
		int v = T[e].v;
		if(v == fa) continue;
		dfs1(v, u, s);
		dis[u] = min(dis[u], dis[v] + 1);
	}
}

int calc(int s) {
	int res = 0;
	for(int i=0; i<n; i++) if(!((s>>i) & 1)) {
		memset(dis, 0, sizeof(dis));
		dfs1(i+1, 0, s);
		res = max(res, dis[i+1]);
	}
	return res;
}

void work() {
	cin>>n>>k;
	for(int i=1; i<n; i++) {
		int u, v; cin>>u>>v;
		addE(u, v); addE(v, u);
	}
	for(int s=(1<<k)-1; s<(1<<n); s++) {
		if(popcnt(s) != k) continue;
		if(!check(s)) continue;
		ans = min(ans, calc(s));
	}
	cout<<ans<<'\n';
}

void init() {
	memset(h, -1, sizeof(h));
	tot = 0;
	ans = inf;
}

int main() {
	fastio;
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--) init(), work();
	return MIKU;
}

//rp ++++++

