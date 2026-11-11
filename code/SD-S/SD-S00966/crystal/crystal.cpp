#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N], sum[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int i = n, j = n;
	int diff = 0, ans = 0;
	while(i > 1 && j > 1) {
		int sta = a[j];
		if (i > j) i = j, diff = 0;
		while (i > 1) {
			int nxt = i - 1;
			int ndiff = diff + (sta - a[nxt]);
			if (ndiff > m) break;
			diff = ndiff;
			--i;
		}
		int len = j - i + 1;
		ans = max(ans, len);
		--j;
		diff -= (len - 1) * (sta - a[j]);
	}
	cout << ans << '\n';
	return 0;
}

