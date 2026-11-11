#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
ll n, m, a[maxn], c[maxn], ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		ll sum = a[i] - a[i - 1];
		c[i] = c[i - 1] + sum;
	}

	ll l = 1, r = 1;

	while (r <= n) {
		if (c[r] - c[l] == m) {
			ans = max(ans, r - l + 1);
			l++, r++;
		} else if (c[r] - c[l] > m)
			l++;
		else
			r++;
	}

	cout << ans;
	return 0;
}
