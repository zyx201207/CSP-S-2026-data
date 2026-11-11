#include <bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define endl '\n'
#define lowbit(x) x&(-x)

#define ll long long
#define int ll
#define ld long double
#define ull unsigned ll

#define PII pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vP vector<PII>
#define fi first
#define se second

const int N = 5e5 + 10;
const int P = 1e12 + 10;

using namespace std;

int n, m;
vi a;

struct Xian_Duan_Tree {

	struct Point {
		int sum;
	} tr[N * 4];

	Point push_up(Point L, Point R) {
		Point fa{};
		fa.sum = L.sum + R.sum;
		return fa;
	}

	void build(int p, int l, int r) {
		if (l == r) {
			tr[p].sum = a[l];
			return ;
		}

		int mid = (l + r) / 2;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		tr[p] = push_up(tr[ls], tr[rs]);
	}

	Point query(int p, int l, int r, int x, int y) {
		if (x <= l && r <= y) {
			return tr[p];
		}

		int mid = (l + r) / 2;
		if (x <= mid && mid + 1 <= y)
			return push_up(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
		else if (x <= mid)
			return query(ls, l, mid, x, y);
		else if (mid + 1 <= y)
			return query(rs, mid + 1, r, x, y);

		return Point();
	}
} TT;

//
mt19937 rng(random_device{}());

void solve() {
	cin >> n >> m;
	a.assign(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] += P;
	}
	sort(a.begin() + 1, a.begin() + 1 + n);

	TT.build(1, 1, n);

	int l = 1, r = n;
	int ok = 0;
	while (l < r) {
		ok = 0;
		int mid = (l + r) / 2;
		for (int i = 1; i + mid - 1 <= n; i ++) {
			int j = i + mid - 1;
			int sum = TT.query(1, 1, n, i, j).sum;
			if (a[j] * mid - sum <= m) {
				ok = 1;
				break;
			}
		}
		if (ok)
			l = mid + 1;
		else
			r = mid;
	}
	cout << l - 1 << endl;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t = 1;
	// cin >> t;
	while (t --)
		solve();
}
