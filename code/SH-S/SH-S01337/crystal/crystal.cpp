#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , ans = 1;
long long m , a[N] , f[N];
int main () {
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	ios::sync_with_stdio (false) , cin.tie (0) , cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1,  a + n + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + a[i];
		int l = 1 , r = i - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid) - f[i - 1] + f[mid - 1] <= m) {
				ans = max (ans , i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
