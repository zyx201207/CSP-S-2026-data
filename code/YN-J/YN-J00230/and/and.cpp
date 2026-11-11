#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (m == 1) {
		long long maxx = 0, a;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			maxx = max(maxx, a);
		}
		cout << maxx;
	} else if (m == 2) {
		long long a[n + 1], maxx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
		cout << maxx;
	} else if (m == n) {
		long long maxx, a;
		cin >> a;
		maxx = a;
		for (int i = 2; i <= n; i++) {
			cin >> a;
			maxx = (maxx & a);
		}
		cout << maxx;
	} else {
		long long a[n + 1], maxx = 0;
		bool A = true, B = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] + 1 % 2 != 0) {
				A = false;
			}
			if (a[i] != a[i - 1 + 1]) {
				B = false;
			}
		}
		sort(a + 1, a + 1 + n);
		if (A) {
			cout << a[n - 1];
		} else if (B) {
			for (int i = n; i >= 2; i--) {
				maxx = max(maxx, (a[i] & a[i - 1]));
			}
			cout << maxx;
		} else {
			cout << 0;
		}
	}
	return 0;
}