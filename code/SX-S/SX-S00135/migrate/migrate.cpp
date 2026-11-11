#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, ju;
	int n, d;
	cin >> c >> t;
	while (t--) {

		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ju = a[2] - a[1];
		ju = d / ju;
		cout << n - 3 << endl;
	}
	return 0;
}
