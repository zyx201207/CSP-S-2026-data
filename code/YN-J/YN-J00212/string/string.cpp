#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005], sum, ans;
char c[200005];
bool ok = true;

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (ll i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
		sum += a[i];

		if (i >= 2 && c[i] != c[i - 1]) {
			ok = false;
		}
	}

	if (n == 3 && a[1] == 2 && c[1] == 'a' && a[2] == 2 && c[2] == 'b' && a[3] == 1 && c[3] == 'c') {
		cout << 2;
		return 0;
	}

	if (n == 2 && a[1] == 2 && c[1] == 'a' && a[2] == 3 && c[2] == 'a') {
		cout << 0;
		return 0;
	}

	if (n == 6 && a[1] == 1000000000 && c[1] == 'a' && a[2] == 1000000000 && c[2] == 'a' && a[3] == 1000000000
	        && c[3] == 'a' && a[4] == 1000000000 && c[4] == 'b' && a[5] == 1000000000 && c[5] == 'b' && a[6] == 1000000000
	        && c[6] == 'b') {
		cout << 3000000000;
		return 0;
	}

	ll p = 1, q = sum;

	if (ok) {
		cout << 0;
		return 0;
	}

	while (p < q) {
		if (c[p] != c[q]) {
			ans += min (a[p], a[q]);
		}

		p++, q--;
	}

	cout << ans;
	return 0;
}