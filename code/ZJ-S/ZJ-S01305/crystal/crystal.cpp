#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], ans = -1e18;
signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 2; i <= n; i++) {
		int mm = m;
		int sum = 1;
		for (int j = i-1; j >= 1; j--) {
			if (mm < 0) {
				sum--;
				break;
			}
			mm -= (a[i] - a[j]);
			sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
