#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l; i <= r; ++ i)
#define D(i, r, l) for(int i = r; i >= l; -- i)
#define int long long
using namespace std;

const int N = 5E5 + 10;
int n, m, ans, a[N], s[N];

inline int calc(int l, int r) {
	int sum = s[r] - s[l - 1];
	return a[r] * (r - l + 1) - sum;
}

signed main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	E(i, 1, n) cin >> a[i];
	stable_sort(a + 1, a + n + 1);
	E(i, 1, n) s[i] = s[i - 1] + a[i];
	
	E(i, 1, n) {
		int l = 1, r = i, res = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(mid, i) <= m) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	
	cout << ans << "\n";
	return 0;
}