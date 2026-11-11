#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int P = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 2e6 + 5;

int c;
int n, d;
int x[maxn];
pair<int, int> dp[maxn];

pair<int, int> get(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return {a.first, a.second + b.second};
	if (a.first < b.first) return a;
	else return b;
}

struct Tree {
	#define lson (rt << 1)
	#define rson (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	struct node {
		int l, r;
		pair<int, int> ans;
	};
	node tr[maxn];
	pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return {a.first, a.second + b.second};
		if (a.first < b.first) return a;
		else return b;
	}
	void build(int rt, int l, int r) {
		tr[rt].l = l, tr[rt].r = r;
		if (l == r) {
			tr[rt].ans = {INF, 0};
			return ;
		}
		build(lson, l, mid);
		build(rson, mid + 1, r);
		tr[rt].ans = merge(tr[lson].ans, tr[rson].ans);
	}
	void update(int rt, int x, pair<int, int> y) {
		int l = tr[rt].l, r = tr[rt].r;
		if (l == r) {
			tr[rt].ans = y;
			return ;
		}
		if (x <= mid) update(lson, x, y);
		if (mid < x) update(rson, x, y);
		tr[rt].ans = merge(tr[lson].ans, tr[rson].ans);
	}
	pair<int, int> query(int rt, int L, int R) {
		int l = tr[rt].l, r = tr[rt].r;
		if (L <= l && r <= R) return tr[rt].ans;
		pair<int, int> ans = {INF, 0};
		if (L <= mid) ans = merge(ans, query(lson, L, R));
		if (mid < R) ans = merge(ans, query(rson, L, R));
		return ans;
	}
	#undef lson
	#undef rson
	#undef mid
} T;

void work() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> x[i];
	int ans = 0;
	for (int i = 1; i <= n; ++ i ) {
		T.build(1, 1, n);
		T.update(1, i, {0, 1});
//		cout << 0 << endl;
//		for (int j = 1; j <= n; ++ j ) {
//			pair<int, int> c = T.query(1, j, j);
//			cout << c.first << " " << c.second << endl;
//		}
		for (int j = i + 1; j <= n; ++  j ) {
			int cc = lower_bound(x + i, x + j + 1, x[j] - d) - x;
//			cout << i << " " << j << " " << cc << endl;
			if (cc == j) continue;
			pair<int, int> w = T.query(1, cc, j - 1);
			w.first ++;
//			cout << w.first << " " << w.second << endl;
			T.update(1, j, w);
			ans += (w.second == 2);
//			cout << j << endl;
//			for (int j = 1; j <= n; ++ j ) {
//				pair<int, int> c = T.query(1, j, j);
//				cout << c.first << " " << c.second << endl;
//			}
		}
	}
	cout << ans << endl;
}

signed main() {
//	system("fc migrate3.ans migrate.out");
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fst;
	
	int t; cin >> c >> t;
	while (t -- ) {
		work();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
