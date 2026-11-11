#include <bits/stdc++.h>
#define long long int;
using namespace std;
int n, m, temp, cnt, ans = 1;
int a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < n; ++i) {
		temp = m, cnt = 0;
		for (int j = i; j >= 0; --j) {
			if (temp >= a[i] - a[j])
				temp -= a[i] - a[j], cnt++;
			else
				break;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}