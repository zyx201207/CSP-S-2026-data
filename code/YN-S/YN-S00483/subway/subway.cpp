#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 5e5 + 5, N = 3e3;

int c, n, m, d, q;

int w[M], a[N][N], t[N][N], k[M];

void f() {
	int x, y, cnt = 0, now, minn = 0x3fffffff;
	cin >> x >> y;
	now = x;
	cnt += w[x];

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= k[i]; j++) {

			if (a[i][k[i]] == now) {
				cnt += t[i][k[i]];
				now = a[i][k[i]];
			}
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k[i];
		int cnt = 0;

		for (int j = 1; j <= k[i]; j++) {

			cin >> a[i][k[i]] >> t[i][k[i]];
			cnt += t[i][k[i]];
		}

		cout << cnt << "\n";
	}

	return 0;
}