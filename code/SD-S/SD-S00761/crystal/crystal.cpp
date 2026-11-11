#include <bits/stdc++.h>
#define ll long long
#define int long long
#define mid ((l + r) >> 1)
#define lowbit(x) ((x) & -(x))

using namespace std;

constexpr int N = 5e5 + 5;

int n, m;
int a[N], pre[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		auto check = [&](int p) -> bool {
			return (pre[i] - pre[p - 1]) + m >= a[i] * (i - p + 1);
		};
		
		int l = 1, r = i, pos = i;
		while (l <= r) {
			if (check(mid)) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		ans = max(ans, i - pos + 1);
	}
	
	cout << ans << '\n';
	
	return 0;
}
