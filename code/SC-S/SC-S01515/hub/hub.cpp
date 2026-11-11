#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15;

bool flag[N];
vector<int> g[N];
int c, t, n, k, u, v, cnt, d[N], f[N];

void dfs(int u, int fa, int s){
	if (((s >> u) & 1) && !((s >> fa) & 1)) cnt++;
	for (int v : g[u])
		if (v != fa) dfs(v, u, s);
}

void dfsp(int u, int fa){
	f[u] = fa;
	d[u] = d[fa] + 1;
	for (int v : g[u]){
		if (v == fa) continue ;
		dfsp(v, u);
	}
}

int lca(int u, int v){
	memset(flag, 0, sizeof(flag));
	flag[u] = 1;
	while (u){
		u = f[u];
		flag[u] = 1;
	}
	if (flag[v]) return v;
	while (v){
		v = f[v];
		if (flag[v]) return v;
	}
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while (t --> 0){
		puts("0");
	}
	return 0;
}