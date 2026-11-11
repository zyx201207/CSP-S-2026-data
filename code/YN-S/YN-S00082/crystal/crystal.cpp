#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m;
int num[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	sort(num + 1, num + 1 + n);
	int pos = n - 1, ans = 0;
	for (int i = n; i >= 1; i--) {
		while (pos > 0 && num[pos] + m >= num[i]) {
			m -= num[i] - num[pos];
			pos--;
		}
		ans = max(ans, i - pos);
		m += (i - pos - 1) * (num[i] - num[i - 1]);
	}
	cout << ans << '\n';
	return 0;
}