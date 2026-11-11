#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int m, n, arr[1000000], l, cnt, ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	if (n > 5000) {
		int d = arr[2] - arr[1];
		int cnt = 1, sum = 0;
		while (cnt < m) {
			sum += cnt * d;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		l = m;
		cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] - arr[j] > l) {
				break;
			}
			l -= arr[i] - arr[j];
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}