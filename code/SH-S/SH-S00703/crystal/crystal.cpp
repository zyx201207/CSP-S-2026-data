#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m, ans, a[N], c[N];

int main () {

	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);

	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a+1, a+n+1);

	for (int i = 1; i <= n; i++) {
		c[i] = c[i-1] + a[i];
	}

	for (int i = 1; i <= n; i++) {
		int L = 1, R = i, u = 0;
		while (L <= R) {
			int mid = L+R>>1;

			long long sum = (i-mid+1)*a[i] - (c[i]-c[mid-1]);

			if (sum <= m) {
				u = mid;
				R = mid-1;
			} else {
				L = mid+1;
			}
		}

		ans = max (ans, 1ll*(i-u+1));
	}

	cout << ans << "\n";

	return 0;
}
