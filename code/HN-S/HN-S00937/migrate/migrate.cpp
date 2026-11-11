#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 10, kInf = 1e9;

struct Tree {
	int l, r, minn, sum;
} tr[kMaxN];

int a[kMaxN], dp[kMaxN], sum[kMaxN], nxt[kMaxN], c, t, n, d, ans;

void B(int id, int l, int r) {
	tr[id] = {l, r, kInf, 0};
	if (l == r) {
		return;
	}
	int mid = l + r >> 1;
	B(id << 1, l, mid), B(id << 1 | 1, mid + 1, r);
}

void D(int id) {
	if (tr[id << 1].minn > tr[id].minn) {
		tr[id << 1].minn = tr[id].minn, tr[id << 1].sum = tr[id].sum;
	} else if (tr[id << 1].minn == tr[id].minn) {
		tr[id << 1].sum += tr[id].sum;
	}
	if (tr[id << 1 | 1].minn > tr[id].minn) {
		tr[id << 1 | 1].minn = tr[id].minn, tr[id << 1 | 1].sum = tr[id].sum;
	} else if (tr[id << 1 | 1].minn == tr[id].minn) {
		tr[id << 1 | 1].sum += tr[id].sum;
	}
	tr[id].minn = kInf, tr[id].sum = 0;
}

void P(int id, int l, int r, int x, int y) {
	if (l <= tr[id].l && tr[id].r <= r) {
		if (tr[id].minn > x) {
			tr[id].minn = x, tr[id].sum = y;
		} else if (tr[id].minn == x) {
			tr[id].sum += y;
		}
		return;
	}
	D(id);
	int mid = tr[id].l + tr[id].r >> 1;
	(l <= mid) && (P(id << 1, l, r, x, y), 0);
	(r > mid) && (P(id << 1 | 1, l, r, x, y), 0);
}

int Q1(int id, int x) {
	if (tr[id].l == tr[id].r) {
		return tr[id].sum;
	}
	D(id);
	int mid = tr[id].l + tr[id].r >> 1;
	return Q1(x <= mid ? (id << 1) : (id << 1 | 1), x);
}

int Q2(int id, int x) {
	if (tr[id].l == tr[id].r) {
		return tr[id].minn;
	}
	D(id);
	int mid = tr[id].l + tr[id].r >> 1;
	return Q2(x <= mid ? (id << 1) : (id << 1 | 1), x);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (cin >> c >> t; t--; ans = 0) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		nxt[n] = n;
		for (int i = n - 1, j = n; i; i--) {
			for (; a[j] - a[i] > d; j--);
			nxt[i] = j;
		}
		if (c == 11 || c == 12) {
			B(1, 1, n), P(1, 1, 1, 0, 1);
			for (int j = 1; j <= n; j++) {
				ans += (Q1(1, j) == 2) * (n - j + 1);
				if (j != n && nxt[j] != j) {
					P(1, j + 1, nxt[j], Q2(1, j) + 1, Q1(1, j));
				}
			}
			cout << ans << '\n';
			continue;
		} else if (c == 13 || c == 14) {
			for (int i = 1; i <= n; i++) {
				int x = nxt[i];
				if (x > i + 1) {
					int y = nxt[nxt[i] - 1];
					int z = nxt[nxt[i] - 2];
					ans += y - z;
				}
			}
			cout << ans << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++) {
			B(1, i, n), P(1, i, i, 0, 1);
			for (int j = i; j <= n; j++) {
				ans += Q1(1, j) == 2;
				if (j != n && nxt[j] != j) {
					P(1, j + 1, nxt[j], Q2(1, j) + 1, Q1(1, j));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
