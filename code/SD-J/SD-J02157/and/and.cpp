// I love HanRui
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[200005], Max, ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	if (m == 1) {
		for (ll i = 1; i <= n; i++) Max = max(Max, a[i]);
		cout << Max;
		return 0;
	}
	if (m == 2) {
		for (ll i = 1; i <= n; i++) 
			for (ll j = 1; j <= n; j++)
				Max = max(Max, a[i] & a[j]);
		cout << Max;
		return 0;
	}
	if (m == n) {
		for (ll i = 2; i <= n; i++)
			Max = a[i] & a[i - 1];
		cout << Max;
		return 0;
	}
	if (m == n - 1) {
		a[0] = a[1];
		for (ll g = 1; g <= n; g++) {
			for (ll i = 1; i <= n; i++) {
				if (i == g) continue;
				else Max = a[i] & a[i - 1];
			}
			ans = max(ans, Max);
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
//10:16
