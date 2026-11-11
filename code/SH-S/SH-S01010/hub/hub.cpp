#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define N 100005
#define M 200005

int c;
int n, k;
int tot, ver[M], nxt[M], head[N];
void add(int u, int v) {
	ver[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

int f[N];
int find(int x) {
	return x != f[x] ? f[x] = find(f[x]) : f[x];
}
void merge(int x, int y) {
	f[find(x)] = find(y);
}

bool b[N];
void dfs(int u, int p) {
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == p) continue;
		if (b[u] && b[v]) merge(u, v);
		dfs(v, u);
	}
}

int dis[N];
int calc() {
	for (int i = 1; i <= n; i++) f[i] = i;
	dfs(1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (b[i] && f[i] == i) cnt++;
	if (cnt > 2) return 2e9;
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q; 
	for (int i = 1; i <= n; i++)
		if (b[i]) {
			q.push(i);
			dis[i] = 0;
		}
	int R = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = nxt[i]) {
			int v = ver[i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
				R = max(R, dis[v]);
			}
		}
	}
	return R;
}

int ans;
void chs(int step, int cnt) {
	if (cnt == k) {
		ans = min(ans, calc());
		return ;
	}
	if (k-cnt > n-step+1) return ;
	b[step] = 1;
	chs(step+1, cnt+1);
	b[step] = 0;
	chs(step+1, cnt);
	b[step] = 0;
}

void solve() {
	tot = 0;
	memset(head, 0, sizeof(head));
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		add(u, v); add(v, u);
	}
	memset(b, 0, sizeof(b)); 
	ans = 2e9;
	chs(1, 0);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T = 1;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
