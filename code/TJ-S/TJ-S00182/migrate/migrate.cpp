/*#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
using namespace std;
const int N = 2e6 + 5;
int n, d, a[N], f[N][2], lst[N], ans;
struct qujian{
	int l, r;
}q[N], p[N];
bool cmp(qujian &A, qujian &B) {
	return A.r < B.r;
}
void solve() {
	cin >> n >> d, ans = 0;
	rep(i, 1, n) cin >> a[i];
	lst[n + 1] = n + 1;
	per(i, n, 1) {
		lst[i] = lst[i + 1];
		while (lst[i] > 1 && a[i] - a[lst[i] - 1] <= d) --lst[i];
		q[i] = {lst[i], i};
	}
	sort(q + 1, q + n + 1, cmp);
	int tot = 0;
	rep(i, 1, n) {
		while (tot && p[tot].l >= q[i].l) --tot; 
		p[++tot] = q[i];
	}
	rep(i, 1, tot) {
		cerr << p[i].l << ' ' << p[i].r << '\n';
	}
	rep(i, 2, tot) {
		if (p[i - 1].r - p[i].l + 1 == 1) {
			f[i][0] = f[i - 1][0] + 1;
		}
	}
	per(i, tot - 1, 1) {
		if (p[i].r - p[i + 1].l + 1 == 1) {
			f[i][1] = f[i + 1][1] + 1;
		}
	}
	rep(i, 1, tot - 1) if (p[i].r - p[i + 1].l + 1 == 2) ans += (f[i][0] + 1) * (f[i + 1][1] + 1);
	cout << ans << '\n';
	rep(i, 1, n) f[i][0] = f[i][1] = lst[i] = 0;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}*/
/*
6 4
-3 0 1 2 3 4
*/
#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
using namespace std;
const int N = 2e6 + 5;
int n, d, a[N], f[N][2], lst[N], nxt[N], dis[N], dp[N], ans;
void solve() {
	cin >> n >> d, ans = 0;
	rep(i, 1, n) cin >> a[i];
	lst[n + 1] = n + 1;
	per(i, n, 1) {
		lst[i] = lst[i + 1];
		while (lst[i] > 1 && a[i] - a[lst[i] - 1] <= d) --lst[i];
	}
	rep(i, 1, n) {
		nxt[i] = nxt[i - 1];
		while (nxt[i] < n && a[nxt[i] + 1] - a[i] <= d) ++nxt[i];
	}
//	if (n <= 300) {
//		rep(i, 1, n) {
//			queue<int> q;
//			rep(j, 1, n) dis[j] = -1;
//			dis[i] = 0;
//			dp[i] = 1;
//			q.push(i);
//			while (!q.empty()) {
//				int x = q.front();
//				q.pop();
//				rep(y, x + 1, nxt[i]) {
//					if (dis[y] == -1) {
//						dis[y] = dis[x] + 1;
//						dp[y] = dp[x];
//						q.push(y);
//					}
//					else if (dis[y] == dis[x] + 1) {
//						dp[y] += dp[x];
//					}
//				}
//			}
//			rep(j, i + 1, n) cerr << i << ' ' << j << ' ' << dis[j] << ' ' << dp[j] << '\n';
//			rep(j, i + 1, n) ans += (dp[j] == 2);
//		}
//		cout << ans << '\n';
//	    rep(i, 1, n) f[i][0] = f[i][1] = lst[i] = nxt[i] = dis[i] = dp[i] = 0;
//		return ;
//	}
	rep(i, 1, n) if (lst[i] != i && (i == n || lst[i] < lst[i + 1])) f[i][0] = f[lst[i]][0] + 1;
	per(i, n, 1) if (nxt[i] != i && (i == 1 || nxt[i] > nxt[i - 1])) f[i][1] = f[nxt[i]][1] + 1;
	rep(i, 1, n) if (nxt[i] - 1 > i) ans += (f[i][0] + 1) * f[nxt[i] - 1][1];
	cout << ans << '\n';
	rep(i, 1, n) f[i][0] = f[i][1] = lst[i] = nxt[i] = dis[i] = dp[i] = 0;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
/*#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
using namespace std;
const int N = 2e6 + 5;
struct SGT{
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	struct node{
		int mn, cnt, id1, id2;
	}t[N];
	void build(int p, int l, int r) {
		t[p].mn = 4e18;
		t[p].cnt = r - l + 1;
		t[p].id1 = l;
		t[p].id2 = 0;
		if (l == r) return;
		t[p].id2 = l + 1;
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
	}
	node merge(node A, node B) {
		node res;
		if (A.mn < B.mn) {
			res.mn = A.mn;
			res.id1 = A.id1;
			res.id2 = A.id2;
			res.cnt = A.cnt;
		}
		else if (A.mn > B.mn) {
			res.mn = B.mn;
			res.id1 = B.id1;
			res.id2 = B.id2;
			res.cnt = B.cnt;
		}
		else {
			res.mn = A.mn;
			res.id1 = A.id1;
			res.id2 = B.id1;
			res.cnt = A.cnt + B.cnt;
		}
		return res;
	}
	void push_up(int p) {
		t[p] = merge(t[ls], t[rs]);
	}
	void update(int p, int l, int r, int x, int val) {
		if (l == r) {
			t[p].mn = val;
			t[p].cnt = 1;
			t[p].id1 = l;
			t[p].id2 = 0;
			return ;
		}
		int mid = l + r >> 1;
		if (x <= mid) update(ls, l, mid, x, val);
		else update(rs, mid + 1, r, x, val);
		push_up(p);
	}
	node query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return t[p];
		int mid = l + r >> 1;
		if (ql <= mid && qr > mid) return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
		if (ql <= mid) return query(ls, l, mid, ql, qr);
		if (qr > mid) return query(rs, mid + 1, r, ql, qr);
	}
}T;
int n, d, a[N], f[N][2], lst[N], nxt[N], ans;
void solve() {
	cin >> n >> d, ans = 0;
	rep(i, 1, n) cin >> a[i];
	lst[n + 1] = n + 1;
	per(i, n, 1) {
		lst[i] = lst[i + 1];
		while (lst[i] > 1 && a[i] - a[lst[i] - 1] <= d) --lst[i];
	}
	rep(i, 1, n) {
		nxt[i] = nxt[i - 1];
		while (nxt[i] < n && a[nxt[i] + 1] - a[i] <= d) ++nxt[i];
	}
	T.build(1, 1, n);
	rep(i, 1, n) {
		if (lst[i] != i) {
			auto tmp = T.query(1, 1, n, lst[i], i - 1);
			cerr << lst[i] << '\n';
			cerr << i << ": " << tmp.mn << ' ' << tmp.cnt << ' ' << tmp.id << '\n';
			if (tmp.cnt == 1) {
				f[i][0] = f[tmp.id1][0] + 1;
				f[i][1] = f[tmp.id1][1] + 1;
			}
			else if (tmp.cnt == 2 && f[tmp.id1][0] && f[tmp.id2][0]) {
				f[i][1] = 
			}
			T.update(1, 1, n, i, tmp.mn + 1);
		}
		else T.update(1, 1, n, i, 0);
		rep(j, 1, n) cerr << T.query(1, 1, n, j, j).mn << ' ';
		cerr << '\n';
	}
//	rep(i, 1, n) if (lst[i] != i && (i == n || lst[i] < lst[i + 1])) f[i][0] = f[lst[i]][0] + 1;
//	per(i, n, 1) if (nxt[i] != i && (i == 1 || nxt[i] > nxt[i - 1])) f[i][1] = f[nxt[i]][1] + 1;
	rep(i, 1, n) cerr << f[i][0] << ' ';
	cerr << '\n';
	rep(i, 1, n) cerr << f[i][1] << ' ';
	cerr << '\n';
    cerr << "-------------\n";
	rep(i, 1, n - 1) ans += f[i + 1][0] * f[i][1];
	cout << ans << '\n';
	rep(i, 1, n) f[i][0] = f[i][1] = lst[i] = nxt[i] = 0;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
*/
