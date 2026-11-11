#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int a[N], f[N], g[N];
signed main() {
	freopen("migrate3.in", "r", stdin);
	freopen("s.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while (T --) {
		int n, d; cin >> n >> d;
		int mn = 2e18;
		for (int i = 1 ; i <= n ; i ++)
			cin >> a[i], mn = min(mn, a[i]);
		cout << n << ' ' << d << '\n';
		for (int i = 1 ; i <= n ; i ++)
			cout << a[i] - mn << ' ';
		cout << '\n'; 
	}
	return 0;
}