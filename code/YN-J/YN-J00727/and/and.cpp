#include <bits/stdc++.h>
using namespace std;

int a[200002];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (m = 1) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > ans)
				ans = a[i];
		}
		cout << ans;
	} else if (m = 2) {
		int max1 = 0;
		bool b[200002] = {};
		for (int i = 0; i < n; i++) {
			if (b[a[i]]==1) {
				if (max1 < a[i]) {
					max1 = [i];
				}
			} else {
				b[a[i]] = 1;
			}
		}
	} else {
		cout << 0;
	}
	return 0;
}