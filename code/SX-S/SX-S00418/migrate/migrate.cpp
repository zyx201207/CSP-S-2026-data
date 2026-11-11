#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, ans, ch;
bool b;
long long x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t > 0) {
		t--;
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		ch = x[2] - x[1];
		for (int i = 2; i <= n; i++) {
			if (x[i] - x[i - 1] != ch) {
				b = 1;
			}
		}
		if (d == 2 * ch && b == 0) {
			ans = n - 3;
		}
		cout << ans;
	}
	return 0;
}
