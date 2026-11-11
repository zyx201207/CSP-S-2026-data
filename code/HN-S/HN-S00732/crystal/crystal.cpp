#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7; 
int n, n2, m;
int a[N], s[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	s[1] = 0;
	for (int i = 2; i <= n; ++i) s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for (int i = 1; i <= n; ++i) {
		if (s[i + 1] > m) {
			cout << i;
			break;
		}
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
