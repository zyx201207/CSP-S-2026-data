#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[2000100], e[2000100], a[2000100];
int get(int n, int x) { // <=x
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	return l - 1;
}
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	scanf ("%lld", &C);
	scanf ("%lld", &T);
	int tot = 0;
	while(T--) {
		int n, m, ans = 0;
		scanf ("%lld %lld", &n, &m);
//		f[1] = e[n] = 1;
		for (int i = 1; i <= n; ++i)
			scanf ("%lld", &a[i]);
		for (int i = n; i >= 1; --i)
			if(i == n || a[i + 1] - a[i] > m) e[i] = i;
			else e[i] = e[i + 1];
		a[n + 1] = a[n] + m + 1;
		for (int i = 2; i < n - 1; ++i) {
			for (int j = i - 1; j >= 1; --j) {
				if(a[i + 2] - a[j] <= m) continue;
				if(a[i + 1] - a[j] > m) break;
				int r = get(n, a[i] + m);
				int l = max(get(n, a[j] + m) + 1, get(n, a[i - 1] + m) + 1);
//				cout << i << " " << j << " " << l << " " << r << endl;
				if(r >= l) ans +=  r - l + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 2
6 4
-3 0 1 2 3 4


0 2
5 3
-3 0 2 3 4
1
1000000000000000000

0 2
10 3
0 3   6 7 8 9 10 11 14  17

9
*/
