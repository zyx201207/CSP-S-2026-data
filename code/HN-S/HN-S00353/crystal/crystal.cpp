#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e5 + 20;
int n, m;
int a[N];
signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	int Max = -1, l = 0, tot = 0;
	for (int i = 1; i <= n; i ++) {
		while ((i - l) * a[i] - tot > m)
			tot -= a[l], l ++;
		Max = max (Max, i - l + 1);
		tot += a[i];
	}
	cout << Max;
	return 0;
}
