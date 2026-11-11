#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e6;
int c, t;
int n, d;
int a[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << (n + 1) % 4 << endl;
	}
	return 0;
}
