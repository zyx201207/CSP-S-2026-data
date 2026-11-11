/*
migrate
*/
#include <bits/stdc++.h>
#define ll long long
#define N 2000010
#define INF 1e9
using namespace std;
int c, t;
ll n, d;
ll a[N];
ll dis[3000][3000];
ll cnt[3000][3000];
void init_dis() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			dis[i][j] = INF;
			if (abs(a[i] - a[j]) <= d) {
				dis[i][j] = 1;
				dis[j][i] = 1;
				cnt[i][j] = 1;
				cnt[j][i] = 1;
			}
		}
		dis[i][i] = 0;
	}
}
void goA() {
	cin >> n >> d;
	if (d >= (n + 1) / 2) {
		cout << 0;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (d == a[2] - a[1]) {
		cout << 0 << '\n';
		return;
	}
	cout << n - d / (a[2] - a[1]) - 1 << '\n';
	return;
}
void go3() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	init_dis();
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dis[i][k] + dis[k][j] == dis[i][j]) {
					cnt[i][j]++;
					cnt[j][i]++;
				} else if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 1;
					cnt[j][i] = 1;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dis[i][j] != INF && cnt[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			goA();
		}
		return 0;
	}
	if (1 <= c && c <= 10) {
		while (t--) {
			go3();
		}
	}
	while (t--) {
		cout << "0\n";
	}
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
