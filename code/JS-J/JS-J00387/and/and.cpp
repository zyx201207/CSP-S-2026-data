#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 9;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	int a[N];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n, greater<int>());
	int ans = a[1];
	for(int i = 1; i <= m; ++i) ans = ans & a[i];
	cout << ans;
	return 0;
}
