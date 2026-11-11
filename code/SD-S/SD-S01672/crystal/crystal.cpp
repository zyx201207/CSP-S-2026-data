#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N], s[N], ans;	
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal.in", "r", stdin);  QAQ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	for (int i = 1, j = 1; j <= n; j++) {
		int cost = a[j] * (j - i + 1) - (s[j] - s[i - 1]);
		for (; cost > m; i++) {
			cost -= a[j] - a[i];
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans << endl;
	return 0;
}
