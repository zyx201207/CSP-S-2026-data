#include <bits/stdc++.h>
using namespace std;
long long s, ss, sss, v[100010], vi[100010], vis[100010], viss[100010], x[100010], d, c, t, n, ans;

void dfs(long long a, long long b, long long k, long long aa) {
	if (a == b) {
		if (s > k) {
			s = k;
			memset(vi, 0, sizeof(vi));
			for (int i = aa; i <= b; i++) {
				if (v[i]) {
					vi[i] = 1;
				}
			}

		}
		return;
	}
	for (int i = a + 1; i <= b; i++) {
		if (x[i] - x[a] <= d) {
			v[i] = 1;
			dfs(i, b, k + 1, aa);
			v[i] = 0;
		} else {
			break;
		}
	}

}

void ddfs(long long a, long long b, long long k, long long aa) {
	if (a == b) {
		if (ss > k) {
			ss = k;
			memset(vis, 0, sizeof(vis));
			for (int i = a; i <= b; i++) {
				if (v[i]) {
					vis[i] = 1;
				}
			}

		}
		return;
	}
	for (int i = a + 1; i <= b; i++) {
		if (x[i] - x[a] <= d && (!vi[i] || i == 4)) {
			v[i] = 1;
			ddfs(i, b, k + 1, aa);
			v[i] = 0;
		} else {
			break;
		}
	}

}

void dffs(long long a, long long b, long long k, long long aa) {
	if (a == b) {
		sss = min(sss, k);
		return;
	}
	for (int i = a + 1; i <= b; i++) {
		if (x[i] - x[a] <= d && (!vi[i] || i == 4) && (!vis[i] || i == 4)) {
			v[i] = 1;
			dffs(i, b, k + 1, aa);
			v[i] = 0;
		} else {
			break;
		}
	}

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				s = LLONG_MAX;
				ss = s;
				sss = s;
				memset(v, 0, sizeof(v));
				dfs(i, j, 0, i);
				memset(v, 0, sizeof(v));
				ddfs(i, j, 0, i);
				memset(v, 0, sizeof(v));
				dffs(i, j, 0, i);
				if (s == ss && s != sss) {
					ans++;
				}
			}
		}
		cout << ans;
	}
}
