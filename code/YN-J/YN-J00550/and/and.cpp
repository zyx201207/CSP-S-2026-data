#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[100005];
long long t;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		t = a[1];
		for (int i = 2; i <= n; i++) {
			t &= a[i];
		}
		cout << t;
		return 0;
	}
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					t = max(t, a[i] & a[j]);
				}
			}
		}
		cout << t;
		return 0;
	}

	return 0;
}