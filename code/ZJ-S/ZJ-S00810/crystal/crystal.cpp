#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N]; 
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int cost = 0, len = 1, ans = 1;
	for (int i = 2, j = 1; i <= n; i++) {
		cost += (a[i] - a[i - 1]) * (i - j);
		len++;
		while (cost > m) {
			cost -= a[i] - a[j];
			j++; len--;
		}
		ans = max(ans, len);
	}
	cout << ans << '\n';
	return 0;
}
