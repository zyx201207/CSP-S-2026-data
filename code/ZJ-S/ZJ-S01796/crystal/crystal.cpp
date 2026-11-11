#include <bits/stdc++.h>
#define int long long
#define ST string
#define DB double

#define fr(x, y, z) for (int x = y; x <= z; x ++ )
#define dfr(x, y, z) for (int x = y; x >= z; x -- )

using namespace std;

const int N = 5e5 + 10;
int n, m, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	fr (i, 1, n) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	int l = 0, cnt = 0, res = 0;
	fr (i, 1, n) {
		cnt += a[i];
		while (a[i] * (i - l + 1) - cnt > m) cnt -= a[l ++ ];
		res = max(i - l + 1, res);
	}
	
	cout << res << '\n';
	
	return 0;
}

// 100
