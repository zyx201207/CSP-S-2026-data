#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m, a[maxn];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
//		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	int nw = 0;
	int ans = 1;
	for(int i = 2, j = 1; i <= n; i++) {
		nw -= (i - j) * a[i - 1];
		nw += (i - j) * a[i];
		while(j <= i && nw > m) nw -= (a[i] - a[j]), j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}
