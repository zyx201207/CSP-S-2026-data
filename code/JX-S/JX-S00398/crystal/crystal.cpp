#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N];
int pre[N];
signed main() {
	// if in submit
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
	// endif
	// if in test
		// freopen("crystal4.in", "r", stdin);
		// freopen("crystal.out", "w", stdout);
	// endif

    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int j = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		while (j <= i && (i - j + 1) * a[i] - (pre[i] - pre[j - 1]) > m) j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
    return 0;
}
