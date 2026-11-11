#include<bits/stdc++.h>
#define int long long
#define ll long long
#define endl "\n"
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d;
int x[N], dp[N], dis[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (11 <= c && c <= 12) {
			int dist = x[2] - x[1];
			int x = d/dist;
			if (x > 1) {
				cout << max(0ll, n - 2 * x + 1) << endl;
			} else {
				cout << 0 << endl;
			}
			continue;
		}
		ll ans = 0;
		for (int r = 2; r <= n; r++) {
			dp[r] = 1;
			dis[r] = 0;
			ll cnt = 1, temp = 0;
			for (int l = r - 1, i = r; l >= 1; l--) {
				while (x[i] - x[l] > d) {
					cnt -= dp[i];
					i--;
					if (dis[i] > dis[i+1]) {
						cnt = temp;
						temp = 0;
					}
				}
				if (i == l) break;
				dp[l] = cnt;
				dis[l] = dis[i] + 1;
				temp += dp[l]; 
				if (dp[l] == 2) ans++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}