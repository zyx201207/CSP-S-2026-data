#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long f = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f = f & a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	if (m == 1) {
		cout << a[1];
	}
	if (m == n) {
		cout << f;
	}
	if (m == 2) {

		int maxg = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int g = 0x3f3f3f;
				if (j != i) {
					g = a[j] & a[i];
				}
				if (g > maxg) {
					maxg = g;
				}
			}
		}
		cout << maxg;
	}
	return 0;
}
