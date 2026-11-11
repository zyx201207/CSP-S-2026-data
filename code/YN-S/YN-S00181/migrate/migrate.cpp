#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long n, a[N], c, cnt[5005][5005], vis[5005][5005], cd[5005][5005], tot, ans, t, d;

void dfs(int q, int now, long long cd1) {
	if (q != now) {
		cd[q][now] = min(cd[q][now], cd1);
//		cout << q << " " << now << " " << cd[q][now] << endl;
	}
	for (int i = now + 1; i <= n && abs(a[i] - a[now]) <= d; i++) {
		dfs(q, i, cd1 + 1);
		tot++;
	}
}

void dfs1(int q, int now, int cd1) {
	if (q != now) {
//		cout << q << " " << now << " " << cd1 << " " << cd[q][now] << endl;
		if (cd1 == cd[q][now]) {
			cnt[q][now]++;
		}
	}
	for (int i = now + 1; i <= n && abs(a[i] - a[now]) <= d; i++) {
		dfs1(q, i, cd1 + 1);
		tot++;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cd[i][j] = 1e18 + 5;
				if (i == j) {
					cd[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			dfs(i, i, 0);
		}
		for (int i = 1; i <= n; i++) {
			dfs1(i, i, 0);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i != j) {
					if (cnt[i][j] == 2) {
						ans++;
					}
					cnt[i][j] = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
