#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long x[123456], y[123456], cnt[123456];
int ok[123456];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int d = 1; d <= n; d++) {
		for (int i = d; i <= n; i++) {
			y[i] = x[i];
			if (ok[y[i]] == 1) {
				for (int w = i - 1; w >= 1; w--) {
					y[w] == 0;
					ok[w] == 0;
					if (y[w] == y[i]) {
						break;
					}
				}
				sort(y + 1, y + n + 1);
			} else {
				ok[y[i]] = 1;
			}
		}
		for (int e = 1; e <= n; e++) {
			if (ok[e] == 1) {
				cnt[e]++;
			}
			ok[e] = 0;
			y[e] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}