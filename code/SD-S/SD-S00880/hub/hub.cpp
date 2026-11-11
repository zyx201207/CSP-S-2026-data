#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
const int inf = 1e9;
int c, T, n, k, u, v, dep[N], fa[N], it, arr[N], mi, ffa[N][21];
vector<int> G[N];
struct info {
	int u, v;
} e[N];
bool vis[N];

void dfs(int p, int fat) {
	dep[p] = dep[fat] + 1;
	ffa[p][0] = fat;
	for(auto to : G[p]) {
		if(to != fat) dfs(to, p);
	}
	return;
}

int find(int p) {
	if(p == fa[p]) return p;
	return fa[p] = find(fa[p]);
}

int LCA(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	int d = dep[y] - dep[x];
	for(int i = 20; i >= 0; i--) {
		if((d >> i) & 1) y = ffa[y][i];
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i--) {
		if(ffa[x][i] != ffa[y][i])
			x = ffa[x][i], y = ffa[y][i];
	}
	return ffa[x][0];
}

void dfs1(int p, int now) {
	if(p == n + 1) {
		if(it != k) return;
		for(int i = 1; i <= n; i++)
			fa[i] = i;
//		for(int i = 1; i <= k; i++)
//			printf("%d ", arr[i]);
//		puts("");
		int maxx = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			int minn = inf;
			for(int j = 1; j <= k; j++) {
				int lca = LCA(i, arr[j]);
				minn = min(minn, dep[i] + dep[arr[j]] - 2 * dep[lca]);
			}
//			printf("%d : minn = %d\n", i, minn);
			maxx = max(maxx, minn);
		}
		int cnt = 0;
		for(int i = 1; i < n; i++) {
			u = e[i].u, v = e[i].v;
			if(vis[u] && vis[v]) {
				int x = find(u), y = find(v);
				if(x != y) fa[y] = x;
			}
		}
		for(int i = 1; i <= k; i++) {
			if(fa[arr[i]] == arr[i]) ++cnt;
		}
//		printf("cnt = %d\nmaxx = %d\n", cnt, maxx);
		if(cnt <= 2) mi = min(mi, maxx);
		return;
	}
	if(now < k) {
		vis[p] = 1;
		arr[++it] = p;
		dfs1(p + 1, now + 1);
		--it;
		vis[p] = 0;
	}
	dfs1(p + 1, now);
	return;
}

void sub1() { // n<=10
	mi = inf;
	it = 0;
	dfs1(1, 0);
	printf("%d\n", mi);
	return;
}

int get(int x, int y) {
	int lca = LCA(x, y);
	return dep[x] + dep[y] - 2 * dep[lca];
}

void sub2() { // k == 2
	mi = inf;
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int maxx = 0;
			for(int o = 1; o <= n; o++)
				maxx = max(maxx, min(get(o, i), get(o, j)));
			mi = min(mi, maxx);
		}
	}
	printf("%d\n", mi);
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			G[i].clear();
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			e[i] = {u, v};
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= n; j++)
				ffa[j][i] = ffa[ffa[j][i - 1]][i - 1];
		}
		if(c <= 3) sub1();
		else sub2();
	}
	return 0;
}
