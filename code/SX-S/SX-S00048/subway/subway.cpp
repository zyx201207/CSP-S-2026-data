//AKCSP-S
#include <bits/stdc++.h>
using namespace std;

struct list {
	int a, t;
} lis[505][505];
int c, n, m, d, q, w[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> lis[i][j].a >> lis[i][j].t;
		}
	}
	while (n--) {
		int x, y;
		cin >> x >> y;
		long long ans = 0;
		for (int i = x; i <= y; i++) {
			ans += min(lis[i][i + 1].t, lis[i][i - 1].t);
		}
		cout << ans;
	}
	return 0;
}
