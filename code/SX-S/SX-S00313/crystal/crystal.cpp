#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+10;
typedef long long ll;
ll n, m, a[N];
ll sum[N];
ll ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (ll i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}

	for (ll i = 1, j = 1; i <= n && j <= n; j++) {
		//cout << " !! " << i << " " << j << " " << sum[j - 1] << " " << sum[i - 1] << endl;
		if (j > i) {

			while (sum[j] - (sum[i - 1] + (a[j] - a[i - 1]) * (i - 1)) > m) {
				i++;
			}
		}

		//cout << i << " " << j << endl;

		ans = max(ans, j - i + 1);
	}

	cout << ans;
	return 0;
}
