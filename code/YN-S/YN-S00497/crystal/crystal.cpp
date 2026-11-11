#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, m, a[N];

int main() {
	// please, don't hack me
	// may the turing glad me
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to change the file name!!!!!
	// be sure to delete any "//"
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	ll x = -1, ans = 0;
	for (ll l = 1, r = 1, d = a[1]; d <= a[n]; d++) {
		//cout << l << " " << r << " " << d << " " << x << "\n";
		x += r - l + 1;
		while (a[r + 1] == d) {
			r++;
		}
		while (x > m ) {
			x -= d - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		//cout << l << " " << r << " " << d << " " << x << "\n";
	}
	cout << ans << "\n";
	return 0;
}