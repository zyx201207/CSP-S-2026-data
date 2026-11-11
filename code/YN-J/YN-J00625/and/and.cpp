#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, b[N], c[N], a[N];
map<int, int>mp;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == n) {
		int v = a[1];
		for (int i = 1; i <= n; i++) {
			v = v & a[i];
		}
		cout << v;
		return 0;
	}
	int k = 30, ans = 0, flag = 1;
	while (k--) {
		flag = 1;
		int tmp = pow(2, k);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if ((a[i]&tmp) && b[i] != -1) {
				b[i] = 1;
				cnt++;
			} else {
				b[i] = -1;
			}
		}
		if (cnt < m) {
			memset(b, 0, sizeof(b));
		}
		if (cnt == m) {
			for (int i = 1; i <= n; i++) {
				if (b[i]) {
					if (flag)
						ans = a[i], flag = 0;
					ans = ans & a[i];

				}
				cout << ans;
				return 0;
			}
		}

	}



	return 0;
}