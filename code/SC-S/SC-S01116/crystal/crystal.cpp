#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define int long long
const int N = 5e5 + 5;
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m; scanf("%lld%lld", &n, &m);
	rep(i, 0, n) scanf("%lld", &a[i]);
	sort(a, a + n);
	int i = 0, j = 0;
	int cst = 0;
	while (j < n) {
		int df = (a[j + 1] - a[j]) * (j - i + 1);
		if (cst + df <= m)
			cst += df, ++j;
		else break;
	}
	int ma = min(j - i + 1, n);
	while (i < n && j < n) {
		ma = max(ma, j - i + 1);
		cst += (a[j + 1] - a[j]) * (j - i + 1); ++j;
		while (cst > m)
			cst -= a[j] - a[i], ++i;
	}
	printf("%lld\n", ma);
	return 0;
}

/*
origin: 1 2 4 8 9
diff:   1 1 2 4 1
sufsum: 9 8 7 5 1

*/