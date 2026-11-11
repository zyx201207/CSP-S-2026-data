#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], b[N], c[N], ans[N], ma = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				if (a[n] == 1)
					ans[1]++;
				else
					ans[1]++, ans[2]++;
			} else {
				if (a[n] == 2)
					ans[2]++;
				else
					ans[1]++, ans[2]++;
			}
		}
		cout << ans[1] << " " << ans[2];
		return 0;
	} else if (m == 1) {
		cout << n;
	} else if (n <= 5000 && m <= 3000 ) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (c[j] == b[j]) {
					continue;
				}
				ans[j]++;
			}
			c[a[i]]++;
		}
		for (int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}

	return 0;
}
