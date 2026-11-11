#include <bits/stdc++.h>
using namespace std;

int c, t;
int n;
long long d;
long long a[2000010];
long long b[2000010];
int cnt;
int cha;

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1) {
				b[i - 1] = a[i] - a[i - 1];
				if (i > 2) {
					if (b[i - 1] == b[i - 2])
						cnt++;
				}
			}
		}
		if (cnt == n - 2) {
			cha = b[1];
			if (2 * cha > d) {
				cout << 0 << "\n";
				continue;
			} else {
				for (int i = 1; i <= n; i++) {
					cout << 1 << "\n";
				}
			}
		} else
			cout << 0 << "\n";

	}

	return 0;
}
