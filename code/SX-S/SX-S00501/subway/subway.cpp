#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q;
ll w[1000005], arr[5005][5005], t[5005][5005], ans[5000005];

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		ans[i] = 1e9;
	for (int i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> arr[i][j] >> t[i][j];
			ans[arr[i][j]] = min(ans[arr[i][j]], t[i][j]);
		}
	}
	for (int i = 1; i <= q; i++) {
		ll st, ed;
		cin >> st >> ed;
		cout << ans[st] + ans[ed] << endl;
	}
	return 0;
}
