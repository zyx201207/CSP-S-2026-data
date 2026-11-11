#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], ans = INT_MIN;

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			ans = max(ans, a[i]);
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = n; j > i; j--) {
				ans = max(ans, a[i] & a[j]);
			}
		}
	}
	cout << ans;
	return 0;
}