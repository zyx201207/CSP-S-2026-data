#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000005], ans;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> d, ans = 0;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n - 3; i++) for (int j = i + 3; j <= n; j++){
			if (x[j] - x[i] <= d) continue;
			if (x[j] - x[i] >= 2 * d) break;
			int cnt = 0;
			for (int k = i + 1; k <= j - 1; k++) if (x[k] - x[i] <= d && x[j] - x[k] <= d) cnt++;
			ans += cnt == 2;
		}cout << ans << endl;
	}
	return 0;
}

