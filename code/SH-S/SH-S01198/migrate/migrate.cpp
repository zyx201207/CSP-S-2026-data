#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[10001], cntx, minx, flag;
void dfs(int step, int now, int end) {
	if (step > minx) return;
	if (now == end) {
		if (step == minx) cntx++;
		else minx = step, cntx = 1;
		return;
	}
	for (int i = n; i > now; i--) {
		if (a[i] - a[now] <= d) dfs(step + 1, i, end);
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		long long ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 2; j <= n; j++) {
				minx = cntx = flag = 0;
				for (int k = i + 2; k <= j; k++) {
					if (a[k] - a[k - 1] > d) {
						flag = 2;
						break;
					}
				}
				if (flag == 2) continue; 
				dfs(0, i, j);
				ans += cntx == 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
