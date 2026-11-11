#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c, t;
long long a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int tt = 0;
		if (a[2] - a[1] <= d) {
			tt = n / 4 + n % 4;
		}
		cout << tt << '\n';
	}
	return 0;
}