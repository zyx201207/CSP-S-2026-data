#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int ans = INT_MIN;

	for (int i = 1; i <= n; i++) {

		int mm = m;
		int cnt = 0;

		for (int j = i - 1; j >= 1; j--) {

			if (mm >= a[i] - a[j]) {
				cnt++;
				mm = mm - (a[i] - a[j]);
			} else {
				break;
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans + 1;
	return 0;
}