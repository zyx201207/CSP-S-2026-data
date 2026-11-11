#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, re[200005], qzy[200005], ans = -INF;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m >> re[1];

	qzy[1] = re[1];

	for (int i = 2; i <= n; i++) {
		cin >> re[i];

		qzy[i] = qzy[i - 1] & re[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int a = not(qzy[i], qzy[j]);

			ans = max(ans, a);
		}
	}

	cout << ans;

	return 0;
}