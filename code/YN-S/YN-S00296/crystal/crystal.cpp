#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
const long long M = 1e18 + 5;
int cnt = 0, n, m, a[N];
long long c[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "W", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = a[i] - a[i - 1];
	}
	sort(a, a + n + 1);
	for (int i = 2; i <= n ; i++) {
		if (c [i] <= m) {
			if (c[i] == 0) {
				m -= c[i];
				cnt += 2;
			} else {
				m -= c[i];
				cnt++;
			}

		}
	}
	cout << cnt;
	return 0;
}