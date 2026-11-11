#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = 0;
int a1[500002];
bool mark = 1, mark2 = 1;
int c;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i];
		if (a1[i] != i)
			mark = 0;
		//
		if (i == 1) {
			c = abs(a1[i + 1] - a1[i]);
		} else {
			if (abs(a1[i] - a1[i - 1]) != c)
				mark2 = 0;
		}
	}
	if (mark == 1) {
		cout << signed((1 + sqrt(1 + 8 * m)) / 2);
		return 0;
	}
	if (mark2 == 1) {
		cout << c << endl;
		cout << signed((1 + sqrt(1 + 8 * m / c)) / 2);
		return 0;
	}
	sort(a1 + 1, a1 + 1 + n);
	int l = 1, r = 1, sum = a1[r] - a1[l], cnt = 1;
	while (l <= n && r < n) {

		if (sum < m) {
			r++;
			sum += (a1[r] - a1[r - 1]) * cnt;
			cnt++;
		} else {
			l++;
			cnt--;
			sum -= a1[r] - a1[r - cnt];
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}