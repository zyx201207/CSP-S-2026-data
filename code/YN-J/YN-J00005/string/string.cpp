#include <bits/stdc++.h>
using namespace std;
long long n;
const long long N = 2e5;
string b[N];
int a[N];

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	long long s, m, c = 0, ans = 0, sum = 0, v = m;
	string x;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
		sum += a[i];
	}

	for (int i = 1; i <= n; i++) {

		if (n % 2 == 0 && i == sum / 2 + 1) {
			break;
		}

		if (n % 2 != 0 && i == sum / 2 ) {
			break;
		}

		if (b[i] != b[n - c]) {
			if (a[i] = a[n - c]) {
				ans += a[i];
			}

			if (a[i] < a[n - c]) {
				ans += a[i];
				s = a[n - c] - a[i];

				if (b[n - c] != b[i + 1]) {
					ans += s;
					a[i + 1] -= s;
				} else {
					a[i + 1] -= s;
				}
			} else {
				ans += a[n - i];
				s = a[i] - a[n - c];

				if (b[i] != b[n - c - 1]) {
					ans += s;
					a[n - c] -= s;
				} else {
					a[n - c] -= s;
				}
			}
		}

		c++;

	}

	if (sum % 2 != 0 && ans != 0) {
		cout << ans - 1;
	} else {
		cout << ans;
	}

	return 0;
}
