#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, ans;
int u[1000005], v[1000005];
bool b = 0;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t > 0) {
		t--;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> u[i] >> v[i];
		}
		if (k >= n) {
			cout << 0;
		} else if (n <= 5) {
			cout << 1;
		} else if (n % 2 == 1) {
			int m = n / 2;
			for (int i = 1; i <= n - 1; i++) {
				if (u[i] != i || v[i] != i + 1 || i > m) {
					b = 1;
				}
				if (i >= m + 1) {
					if (u[i] != i - m || v[i] != i + 1) {
						b = 1;
					}
				}
			}
			if (b == 0) {
				if (k >= m) {
					cout << 1;
				}
			}
		}
	}
	return 0;
}
