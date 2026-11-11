#include <bits/stdc++.h>
using namespace std;
int x[200001];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, ans = 1;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		if (x[0] > 0) {
			cout << ans << endl;
			ans++;
		}else {
			cout << ans - 1 << endl;
			ans++;
		}
	}
	return 0;
}