#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<ll>c;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m, x, ans = 0;
	cin >> n >> m;

	for (ll i = 0; i < n; i++) {

		cin >> x;
		c.push_back(x);
	}

	sort(c.begin(), c.end());
	ll 	N = n;

	for (ll j = m; j > 0; j++) {

		n /= 2;
		ll val = c[n], M = m;

		for (ll i = 0; i < N; i++) {

			if (c[i] == val)
				ans++;
		}

		for (ll i = n - 1; i >= 0; i--) {

			if (c[i] < 0 && val > 0) {
				m -= abs(c[i]);
				m -= abs(val);
				ans++;
				//cout << endl << m << " ";

				if (m <= 0)
					break;
			} else if (c[i] > 0 && val > 0) {
				m -= abs(val - c[i]);
				ans++;
				cout << endl << m << " ";

				if (m <= 0)
					break;
			} else if (c[i] < 0 && val < 0) {
				m -= abs(abs(c[i]) - abs(val));
				ans++;

				if (m <= 0)
					break;
			} else if (c[i] > 0 && val < 0) {
				m -= abs(val);
				m -= c[i];
				ans++;

				if (m <= 0)
					break;
			}

			cout << endl << m << endl;

		}

	}

	if (m < 0) {
		ans--;
	}

	//cout << m << " ";
	cout << ans;
	return 0;
}