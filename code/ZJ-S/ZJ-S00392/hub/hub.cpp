#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int c, t, n, k, ans = INT_MAX;
int idx = 0, h[N], ne[N << 1], e[N << 1];
int mrk[N], f[N], vis[N];
void add(int u, int v) {
	e[++idx] = v, ne[idx] = h[u], h[u] = idx;
}
int get(int u) {;
	if(f[u] == u) return u;
	f[u] = get(f[u]);
	return f[u];
}
bool check() {
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int u = 1; u <= n; u++) {
		if(mrk[u] == 0) continue;
		for(int i = h[u]; i; i = ne[i]) {
			int v = e[i];
			if(mrk[v] == 0) continue;
			int fu = get(u);
			int fv = get(v);
			f[fu] = fv;
		}
	}
	int cnt = 0;
	for(int u = 1; u <= n; u++) {
		if(mrk[u] == 0) continue;
		if(f[u] == u) cnt++;
	}
	if(cnt <= 2) return true;
	return false;
}

int getdis(int st) {
	queue<pair<int, int>> q;
	q.push({st, 0});
	memset(vis, 0, sizeof(vis));
	vis[st] = 1;
	while(!q.empty()) {
		int u = q.front().first;
		int step = q.front().second;
		q.pop();
		for(int i = h[u]; i; i = ne[i]) {
			int v = e[i];
			if(mrk[v] == 1) return step + 1;
			vis[v] = 1;
			q.push({v, step + 1});
		}
	}
	return n;
}

void calc() {
	int tmp = 0;
	if(!check()) return;
	for(int i = 1; i <= n; i++) {
		if(mrk[i] == 1) continue;
		tmp = max(tmp, getdis(i));
	}
	ans = min(ans, tmp);
	return;
}
void dfs(int i, int sel) {
	if(sel == k) {
		calc();
		return;
	}
	if(i > n) return;
	mrk[i] = 1;
	dfs(i + 1, sel + 1);
	mrk[i] = 0;
	dfs(i + 1, sel);
	return;
}
void init() {
	ans = INT_MAX;
	idx = 0;
	for(int i = 1; i <= n; i++) h[i] = 0;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &c, &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		init();
		for(int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add(u, v);
			add(v, u);
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
