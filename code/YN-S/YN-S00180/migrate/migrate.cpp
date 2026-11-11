#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
long long a[2000005], b[2000005], c[2000005];
long long ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> T >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		memset(b, 0x3f, sizeof(b));
		b[1] = 0;
		c[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				if (a[i] - a[j] > m) {
					break;
				}
				if (b[i] > b[j] + 1) {
					c[i] = c[j];
					b[i] = b[j] + 1;
				} else if (b[i] == b[j] + 1) {
					c[i] += c[j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] == 2) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
