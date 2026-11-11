#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int j = 1, sum = 0, ans = 0;
	for(int i = 1; i <= n && j <= n; i++) {
		while(j <= n && a[j] * (j - i + 1) - sum - a[j] <= m) sum += a[j++];
//		cout << i << " " << j << " " << sum << endl;
		ans = max(ans, j - i);
		sum -= a[i];
	}
	cout << ans;
	return 0;
}
