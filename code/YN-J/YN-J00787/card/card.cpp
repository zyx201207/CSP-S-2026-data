#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 1e5 + 10;
int a[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] < a[i + 1]) {
			cnt++;
		}
	}
	if (cnt == n) {
		for (int i = 1; i <= n; i++) {
			cout << n - i + 1 << " ";
		}
		return 0;
	}
	if (m == 1) {
		cout << n;
		return 0;
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (m == 2) {
		int cnta = 0, cntb = 0;
		sort(a + 1, a + n + 1);
		int x = a[1];
		for (int i = 1; i <= n; i++) {
			if (a[i] == x) {
				cnta++;
			} else {
				cntb++;
			}
		}
		cout << cnta << " " << cntb;
	}
	return 0;
}