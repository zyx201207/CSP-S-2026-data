#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], f[500005], l, r, mid, ans, gm;
signed main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)  cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)  f[i] = f[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for (int i = 1; i <= n; i++){
		l = 1, r = i, gm = -1e9;
		while (l <= r){
			mid = l + (r - l) / 2;
			int temp = f[i] - f[mid] - (mid - 1) * (a[i] - a[mid]);
			if (temp <= m){
				gm = i - mid + 1;
				r = mid - 1;
			}
			else  l = mid + 1;
		}
		ans = max (ans, gm);
	}
	cout << ans;
	return 0;
}
