#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
ll n, a[N], ans;
char c[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (ll i = 1, j = n; i < j; ) {
		bool add = c[i] != c[j];
		if (a[i] > a[j]) {
			if (add) ans += a[j];
			a[i] -= a[j];
			a[j] = 0; j--;
		} else if (a[i] < a[j]) {
			if (add) ans += a[i];
			a[j] -= a[i];
			a[i] = 0; i++;
		} else {
			if (add) ans += a[i];
			a[i] = a[j] = 0;
			i++; j--;
		}
	}
	cout << ans << "\n";
	return 0;
}

