#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], k[505], x, y, r, minn;
bool xy;

struct stu {
	map<int, int>a, t;
} tlbc[505];

void dfs(int lc, int lk, int ck, int kc) {
	if (lc == y) {
		minn = min(minn, lk);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (tlbc[i].a[1] == lc) {
			if (i == ck) {
				dfs(tlbc[i].a[2], lk, ck, 2);
			} else {
				dfs(tlbc[i].a[2], lk + tlbc[ck].t[kc] + tlbc[i].t[1], i, 1);
			}
		}
	}
}

void dfss(int lc, int lk, int ck, int kc) {
	if (lc == y) {
		minn = min(minn, lk);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (tlbc[i].a[j] == lc) {
				for (int kk = j + 1; kk <= k[i]; kk++) {
					if (i == ck) {
						dfs(tlbc[i].a[kk], lk, ck, kk);
					} else {
						dfs(tlbc[i].a[kk], lk + tlbc[ck].t[kc] + tlbc[i].t[j], i, j);
					}
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (k[i] != 2) {
			xy = 1;
		}
		for (int j = 1; j <= k[i]; j++) {
			cin >> tlbc[i].a[j] >> tlbc[i].t[j];
		}
	}
	while (q--) {
		minn = 2100000000;
		cin >> x >> y;
		if (x == y) {
			cout << 0 << endl;
			continue;
		}
		if (xy == 0) {
			for (int i = 1; i <= n; i++) {
				if (tlbc[i].a[1] == x) {
					dfs(x, w[x] + w[y], i, 1);
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k[i]; j++) {
					if (tlbc[i].a[j] == x) {
						dfs(x, w[x] + w[y], i, j);
					}
				}
			}
		}
		cout << minn << endl;
	}
	return 0;
}