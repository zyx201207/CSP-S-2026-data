#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], s[N];

signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int res = 1;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < i && (i - j + 1) * a[i] - (s[i] - s[j - 1]) > m) j += 1;
		res = max(res, i - j + 1);
	}
	cout << res << '\n';
	return 0;
}
