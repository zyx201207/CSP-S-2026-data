#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long n, m, a[N], mn[N], f[N][N];
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + 1 + n);
	memset (mn, 0x3f, sizeof mn);
	mn[1] = 0;
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			f[i][j] = f[i][j - 1] + (a[j] - a[j - 1]) * (len - 1);
			mn[len] = min (mn[len], f[i][j]);
		}
	}
	for (int i = n; i >= 1; i--)
		if (m >= mn[i]) {
			cout << i;
			break;
		}
	return 0;
}
