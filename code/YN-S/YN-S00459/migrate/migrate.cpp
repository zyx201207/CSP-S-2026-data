#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			cout << n % (a[2] - a[1] + d - d % (a[2] - a[1])) << "\n";
		}
	}
	//????Ð¦Ð¦ËãÁË¡£
	return 0;
}