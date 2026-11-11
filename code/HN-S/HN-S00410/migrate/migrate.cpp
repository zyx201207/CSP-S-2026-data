#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
//#define ull unsigned long long
const int N = 2e6;
int x[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		cout << n / d - 1 + (n % d == 0 ? 0 : 1) << "\n";
	}
	return 0;
}
