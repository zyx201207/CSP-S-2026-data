#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500010];
int sam;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i  = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int san = 0;
	for (int i = 1, j = 1; j <= n; j++) {
		san += (j - i) * (a[j] - a[j - 1]);
		while (san > m) {
			san -= a[j] - a[i];
			i++;
		}
		sam = max(sam, j - i + 1);
	}
	cout << sam;
	return 0;
}
