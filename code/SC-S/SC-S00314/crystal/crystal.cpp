#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], l, r, ans, tmp;

signed main()
{
	freopen("crystal.in", "r" , stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	l = r = 1;
	while (r <= n) {
		while (tmp > m) {
			tmp -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		tmp += (r - l + 1) * (a[r + 1] - a[r]);
		r++;
	}
	
	cout << ans;
	
	return 0;
}