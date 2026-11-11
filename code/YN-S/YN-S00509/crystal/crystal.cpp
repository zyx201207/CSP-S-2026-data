#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m;
ll a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);
	ll ans = 1;
	ll sum = 0;
	ll x = 1;

	for (int i = n; i >= 1; i--) {

		x = 0, sum = 0;

		while (sum <= m && i - x  >= 1) {
			sum = sum + a[i] - a[i - x ];
			x++;
		}

		if (sum > m)
			x--;
		ans = max(ans, x);
	}

	cout << ans;


	return 0;
}