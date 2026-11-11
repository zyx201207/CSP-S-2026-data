#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c, t;
ll n, d;
ll a[510];
ll b[2000010];
ll zy[510];
ll ab[510][510], sum[510][510];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> b[i];
		}
		bool f = 1;
		for (ll i = 2; i <= n - 1; i++) {
			if (b[i] - b[i - 1] != b[i + 1] - b[i]) {
				f = 0;
				break;
			}
		}
		if (f) {
			ll cnt = 0;
			for (ll i = 2; b[i] - b[1] <= d; i++) {
				cnt = i - 1;
			}
			cout << max(0ll, n - 2 * cnt + 1) << endl;
			continue;
		} else {
			for (ll i = 1; i <= n; i++) {
				a[i] = b[i];
			}
			a[0] = a[1];
			ll cnt = 1;
			for (ll i = 1; i <= n + 1 && cnt <= n; i++) {
				if (i == n + 1 || a[i] - a[cnt] > d) {
					zy[cnt] = i - 1;
					//cout << zy[cnt] << " ";
					i--;
					cnt++;
				}
			}
			memset(ab, 0x3f, sizeof(ab));
			for (ll i = 1; i <= n; i++) {
				for (ll j = i + 1; j <= n; j++) {
					if (zy[i] >= j) {
						ab[i][j] = 1;
					}
					//cout << ab[i][j] << " " << i << " " << j << "###";
					//cout << zy[i] << " " << j << "%%%";
				}
				//cout << endl;
			}
			for (ll i = 1; i <= n; i++) {
				for (ll k = i + 1; k <= n; k++) {
					for (ll j = k + 1; j <= n; j++) {
						if (ab[i][k] + ab[k][j] < ab[i][j]) {
							ab[i][j] = ab[i][k] + ab[k][j];
							sum[i][j] = 1;
						} else if (ab[i][j] == ab[i][k] + ab[k][j]) {
							sum[i][j]++;
						}
					}
				}
			}
			ll ans = 0;
			for (ll i = 1; i <= n; i++) {
				for (ll j = 1; j <= n; j++) {
					//cout << sum[i][j] << " ";
					if (sum[i][j] == 2) {
						//cout << i << " " << j << endl;
						ans++;
					}
				}
				//cout << endl;
			}
			cout << ans << endl;
		}

	}
	return 0;
}