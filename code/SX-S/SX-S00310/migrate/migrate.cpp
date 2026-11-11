#include <bits/stdc++.h>
using namespace std;

int c, t;
int n, d;
int x[2000005];
int ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> n >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			ans += x[i];
		}
		cout << ans << endl;
	}
	return 0;
}