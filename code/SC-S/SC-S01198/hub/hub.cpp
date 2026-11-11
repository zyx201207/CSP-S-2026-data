#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
int c, T, n, k, x, y;
int fa[maxn], dep[maxn], vis[maxn], son[maxn], siz[maxn], dis[maxn], Max[maxn];
vector<int> e[maxn];
void dfs(int u, int lst) {
	fa[u] = lst, dep[u] = dep[lst] + 1;
	for (int v : e[u]) {
		if (v == lst) continue;
		dfs(v, u);
	}
	return ;
}
void get_path(int ss, int tt) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	vis[ss] = vis[tt] = 1;
	while (ss != tt) {
		if (dep[ss] > dep[tt]) swap(ss, tt);
		tt = fa[tt], vis[tt] = 1;
	}
	return ;
}
void get_dis(int ss, int tt) {
	for (int i = 1; i <= n; i++) dis[i] = -1;
	dis[ss] = dis[tt] = 0;
	queue<int> q;
	q.push(ss), q.push(tt);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : e[u]) {
			if (dis[v] != -1) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	return ;
}
void get_son(int u, int lst) {
	son[u] = siz[u] = 1, Max[u] = dis[u];
	for (int v : e[u]) {
		if (v == lst || vis[v]) continue;
		get_son(v, u);
		siz[u] += siz[v];
		Max[u] = max(Max[u], Max[v]);
	}
	return ;
}
void check(int u, int lst, int mid, int &cnt) {
	if (lst != 0 && Max[u] - dis[u] < mid) {
		cnt -= siz[u];
		return ;
	}
	for (int v : e[u]) {
		if (v == lst || vis[v]) continue;
		check(v, u, mid, cnt);
	}
	return ;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		e[x].push_back(y), e[y].push_back(x);
	}
	dfs(1, 0);
	int Min = n;
	for (int s = 1; s <= n; s++) {
		for (int t = s + 1; t <= n; t++) {
			get_path(s, t);
			get_dis(s, t);
			for (int i = 1; i <= n; i++)
				son[i] = Max[i] = 0;
			get_son(s, 0), get_son(t, 0);
			int l = 0, r = n, mid, tot = 0, ans = n;
			for (int i = 1; i <= n; i++) {
				if (!son[i]) l = max(l, dis[i]);
				else tot++;
			}
			while (l <= r) {
				mid = (l + r) >> 1;
				int cnt = tot;
				check(s, 0, mid, cnt), check(t, 0, mid, cnt);
				if (cnt <= k) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			Min = min(Min, ans);
		}
	}
	cout << Min << '\n';
	return ;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}