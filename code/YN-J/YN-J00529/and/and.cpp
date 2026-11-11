#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int n, m;



int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int pow2 = 0;
	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (((a[i]) & (a[i] + 1)) == 0)
			pow2++;
		if (a[i] == (i - 1))
			cnt1++;
	}
	ll maxand = 0;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			maxand = max(maxand, a[i]);
		}
		cout << maxand;
		return 0;

	} else if (m == n) {
		maxand = a[1];
		for (int i = 2; i <= n; i++) {
			maxand &= a[i];
		}
		cout << maxand;
		return 0;

	} else if (m == 2) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ll ans = (a[i] & a[j]);
				if (i == j) {
					continue;
				}
				maxand = max(ans, maxand);
			}
		}
		cout << maxand;
		return 0;

	} else if (pow2 == n) {
		sort(a + 1, a + n + 1, greater<int>());
		cout << a[m];
		return 0;
	} else if (((n & (n - 1)) == 0) && cnt1 == n) {

		int temp = m;
		int templow = 1;
		int temphigh = 2;
		if (temp == 0 || temp == 1) {
			cout << 0;
			return 0;
		}
		while (1) {
			templow *= 2;
			temphigh *= 2;
			if ((temp > templow) && (temp <= temphigh)) {
				break;
			}
		}
		cout << n - temphigh << endl;
		return 0;
	}

	return 0;
}
