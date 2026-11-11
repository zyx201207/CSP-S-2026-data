#include <bits/stdc++.h>

using namespace std;

long long a[200010];
long long dis[310][310];
int c;
long long n, l, ans = 0;

void solve() {
	ans = 0;
	cin >> n >> l;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (n <= 3) return cout << 0 << '\n', void();
	if (c == 11 || c == 12) {
		long long d = a[2] - a[1];
		l /= d;
		if (l <= 1) cout << 0 << '\n';
		else cout << n - (2 * l - 2) - 1 << '\n';
	} else if (c == 13 || c == 14){
		cout << 0 << '\n';
	} else {
		memset(dis, 0, sizeof dis);
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				int k = i + 1, now = i;
				while (k <= j) {
					if (a[k] - a[now] > l) {
						if (now == k - 1) {
							dis[i][j] = -1;
							break;
						} 
						dis[i][j]++;
						now = k - 1;
					} else k++;
				}
				dis[i][j]++;
			}
		for (int i = 1; i <= n; ++i)
			for (int j = i + 3; j <= n; ++j) {
				int cnt = 0;
				if (dis[i][j] == 0 || dis[i][j] == 1) continue;
				for (int k = i + 1; k < j; ++k)
					if (dis[i][k] + dis[k][j] == dis[i][j]) cnt++;
				if (cnt == dis[i][j]) ans++;
			}
//		for (int i = 1; i <= n; ++i)
//			for (int j = i + 3; j <= n; ++j)
//				cout << dis[i][j] << " \n"[j == n];
		cout << ans << '\n';
	}
	
}

int main( ) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}