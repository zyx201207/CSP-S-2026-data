#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define vec vector
#define pb push_back
#define pii pair< int, int >
#define pll pair< ll, ll >

const int N = 2e6 + 10;

int n;
ll d;
ll a[N];
ll f[N], g[N];

struct SGT {
	
ll mn[N << 2], cnt[N << 2];

void pushup(int u) {
	mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
	if (mn[u << 1] < mn[u << 1 | 1]) cnt[u] = cnt[u << 1];
	else if (mn[u << 1] > mn[u << 1 | 1]) cnt[u] = cnt[u << 1 | 1];
	else cnt[u] = cnt[u << 1] + cnt[u << 1 | 1];
}

void build(int u, int l, int r) {
	if (l == r) {
		mn[u] = 1e18; cnt[u] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int x, int k1, ll k2) {
	if (l == r) {
		mn[u] = k1, cnt[u] = k2;
		return ;
	}
	int mid = l + r >> 1;
	if (x <= mid) update(u << 1, l, mid, x, k1, k2);
	else update(u << 1 | 1, mid + 1, r, x, k1, k2);
	pushup(u);
}

pll query(int u, int l, int r, int x, int y) {
	if (x > y) return make_pair(1e18, 0);
	if (x <= l && r <= y) return make_pair(mn[u], cnt[u]);
	int mid = l + r >> 1; pll lft = make_pair(1e18, 0), rgt = make_pair(1e18, 0);
	if (x <= mid) lft = query(u << 1, l, mid, x, y);
	if (y > mid) rgt = query(u << 1 | 1, mid + 1, r, x, y);
	if (lft.fi < rgt.fi) return lft;
	if (lft.fi > rgt.fi) return rgt;
	return make_pair(lft.fi, lft.se + rgt.se);
}

}T;

void solve1() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	ll cnt = 0;
	for (int s = 1; s <= n; s ++) {
		for (int i = 1; i <= n; i ++) f[i] = 1e18, g[i] = 0;
		f[s] = 0, g[s] = 1;
		T.build(1, 1, n);
		T.update(1, 1, n, s, f[s], g[s]);
		for (int i = s + 1, j = s; i <= n; i ++) {
			while (j <= i && a[i] - a[j] > d) j ++;
			pll x = T.query(1, 1, n, j, i - 1);
			f[i] = min(f[i], x.fi + 1), g[i] = x.se;
			T.update(1, 1, n, i, f[i], g[i]);
		}
		for (int i = 1; i <= n; i ++) {
			if (g[i] == 2) cnt ++;
		}
	}
	cout << cnt << '\n';
}

void solve2() {
	cin >> n >> d; //cerr << n << " " << d << '\n';
	for (int i = 1; i <= n; i ++) cin >> a[i];
	ll D = a[2] - a[1];
	ll k = d / D;
	if (n == 1 || d < D || k == 1) {
		cout << 0 << '\n';
		return ;
	}
	
	ll cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += (i + 2 * k - 1) <= n;
	}
	cout << cnt << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	clock_t st = clock();
	
	int c, T = 1;
	cin >> c >> T;
	if (c != 11 && c != 12) {
		while (T --) solve1();
	}
	else {
		while (T --) solve2();
	}
	
	clock_t ed = clock();
	cerr << "time:" << (double)(ed - st) / (double)CLOCKS_PER_SEC << "s" << '\n';
	return 0;
}