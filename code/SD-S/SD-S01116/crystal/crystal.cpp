#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e5 + 5;
int n, m, ans, a[N], f[N], g[N];
bool check(int lim, int x) {
	return (g[x] - g[lim - 1] - (x - lim + 1) * (a[n] - a[x])) <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1 ; i <= n ; ++i) f[i] = a[n] - a[i];
	for (int i = 1 ; i <= n ; ++i) g[i] = g[i - 1] + f[i];
	for (int i = 1 ; i <= n ; ++i) {
		int l = 1, r = i, num = 1e9; //¶þ·ÖÎ»ÖÃ 
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, i)) {
				num = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
//		if (i - num + 1 > ans) cout << i << "\n";
		ans = max(ans, i - num + 1);
	}
	cout << ans;
//	for (int i = 1 ; i <= n ; ++i)
//	for (int j = 1 ; j < i ; ++j)
//	cout << j << "  " << i << " : " << check(j, i) << "\n";	
	return 0;
}
//5 5
//1 2 4 8 9
