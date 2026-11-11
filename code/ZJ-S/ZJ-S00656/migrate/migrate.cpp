#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, d, x[N];
inline void solA() {
	cin >> n >> d;
	for(int i = 1; i <= n; ++i) cin >> x[i];
	if(n <= 1) {
		cout << "0\n";
		return;
	}
	int dd = x[2] - x[1];
	if(dd > d) {
		cout << "0\n";
		return;
	}
	int ans = 0, k = d / dd;
	for(int i = 1; i <= n; ++i) {
		if(k + i >= n) break;
		ans += min((k << 1) + i - 1, n) - (k + i);
	}
	cout << ans << '\n';
}
inline void sol() {
	
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	int c, T;
	cin >> c >> T;
	solA();
	return 0;
}