#include<bits/stdc++.h>
#define mid (l+r>>1)
#define ls u<<1,l,mid
#define rs u<<1|1,mid+1,r
#define int long long
using namespace std;
#define N 5005
vector<pair<int, int>>mp[N << 3];
int T, c, n, d, idx, ans, a[N], jl[N], dis[N], cnt[N], p[N << 2], inf = 2e18;
struct dq {
	int l = N, r = N - 1, a[N * 2];
	void puf (int x) {
		l--, a[l] = x;
	}
	void pub (int x) {
		r++, a[r] = x;
	}
	int top() {
		return a[l];
	}
} q;
void bfs (int st) {
	for (int i = 1; i <= idx; i++) dis[i] = inf, cnt[i] = jl[i] = 0;
	q.pub (st), dis[st] = 0, cnt[st] = 1;
	while (q.l <= q.r) {
		int u = q.top();
		q.l++;
		if (jl[u]) continue;
		jl[u] = true;
		for (auto i : mp[u]) {
			int v = i.first, w = i.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w, cnt[v] = cnt[u];
				w ? q.pub (v) : q.puf (v);
			} else if (dis[v] == dis[u] + w) cnt[v] += cnt[u];
		}
	}
}
void build (int u, int l, int r) {
	p[u] = ++idx;
	if (l == r) {
		mp[p[u]].emplace_back (l, 0);
//	cout<<idx<<' ';
		return;
	}
	build (ls), build (rs);
	mp[p[u]].emplace_back (p[u << 1], 0);
	mp[p[u]].emplace_back (p[u << 1 | 1], 0);
}
void update (int u, int l, int r, int L, int R, int st) {
	if (L <= l && r <= R) {
		mp[st].emplace_back (p[u], 1);
		return;
	}
	if (L <= mid) update (ls, L, R, st);
	if (R > mid) update (rs, L, R, st);
}
signed main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d, idx = n, ans = 0;
//	build (1, 1, n);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1, j = 1; i <= n; i++) {
			while (a[j + 1] - a[i] <= d && j < n) j++;
			if (i < j) {
				for (int v = i + 1; v <= j; v++) mp[i].emplace_back (v, 1);
//	update (1, 1, n, i + 1, j, i);
			}
		}
		vector<int>v;
		for (int i = 1; i < n; i++) {
			if (c <= 10 || i == 1) {
				bfs (i);
				for (int j = i + 1; j <= n; j++) if (cnt[j] == 2) ans++, v.emplace_back (j);
			} else {
				while (v.size() && v.back() + i - 1 > n) v.pop_back();
				ans += v.size();
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= idx; i++) mp[i].clear();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 100

*/