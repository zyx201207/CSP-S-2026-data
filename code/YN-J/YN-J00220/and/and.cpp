#include <bits/stdc++.h>
using namespace std;
int m, n, a[30000];
int ans;

int main() {
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = int(ans & a[i]);
		}
	}
	if (m == 1) {
		ans = a[n];
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i != j) {
					ans = max(ans, int(a[i] & a[j]));
				}

			}
		}
	}
	cout << ans;
	return 0;
}