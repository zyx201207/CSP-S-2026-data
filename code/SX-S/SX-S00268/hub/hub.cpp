#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, k, head[1000005], nxt[2000005], tail[2000005], tot, dis[1000005], dep[1000005], g[1000005], Lim, Rt;

inline void add_edge(int u, int v) {
	tail[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	tail[++tot] = u;
	nxt[tot] = head[v];
	head[v] = tot;
	return;
}

inline void dfs(int x, int fa) {
	dis[x] = dis[fa] + 1;
	dep[x] = 1;
	g[x] = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if (ed == fa)
			continue;
		dfs(ed, x);
		g[x] += g[ed];
		dep[x] = max(dep[x], dep[ed] + 1);
	}
	if (dep[x] > Lim || x == Rt)
		++g[x];
	return;
}

inline int dfs2(int x, int fa, int now) {
	if (now > Lim)
		return n + 1;
	int res = g[x];
	int mx = -1e8, mx2 = -1e8, mxid = -1;
	if (dis[x] > Lim)
		mx = 0, mx2 = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if (ed == fa)
			continue;
		if (dep[ed] > mx) {
			mx = dep[ed];
			mxid = ed;
		} else if (dep[ed] > mx2)
			mx2 = dep[ed];
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if (ed == fa)
			continue;
		if (ed == mxid) {
			if (mx2 + dis[x] - 1 <= Lim)
				res = min(res, dfs2(ed, x, now));
			else
				res = min(res, dfs2(ed, x, max(now + 1, mx2 + 1)));
		} else {
			if (mx + dis[x] - 1 <= Lim)
				res = min(res, dfs2(ed, x, now));
			else
				res = min(res, dfs2(ed, x, max(now + 1, mx + 1)));
		}
	}
	return res;
}

inline int chk(int x) {
	Lim = x;
	int res = n + 1;
	int mxds = 0;
	for (int i = 1; i <= n; ++i) {
		dis[0] = 0;
		Rt = i;
		for (int j = 1; j <= n; ++j) {
			mxds = max(mxds, dis[j] - 1);
		}
		for (int j = head[i]; j; j = nxt[j]) {
			int ed = tail[j];
			res = min(res, dfs2(ed, i, -1e8) + g[i] - g[ed]);
		}
	}
	if (mxds <= Lim)
		res = 0;
	return res;
}

void work() {
	n = read();
	k = read();
	if (k == n) {
		printf("0\n");
		return;
	}
	for (int i = 1; i <= n; ++i)
		head[i] = 0;
	tot = 0;
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		add_edge(u, v);
	}
	int l = 1, r = n, res = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (chk(mid) <= k) {
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	printf("%d\n", res);
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int Tec = read(), T = read();
	while (T--) {
		work();
	}
	return 0;
}