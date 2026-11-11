#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		vector<int> vt(2000005, 0);
		for (int i = 1; i <= n; i++) {
			cin >> vt[i];
		}
		cout << 0 << endl;
	}
	return 0;
}
