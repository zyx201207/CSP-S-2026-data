#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], l, r, num, sum, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = a[1];
	for (int i = 1; i <= n; i++) {
		if (sum + num * (a[i] - a[i - 1]) > m || num > n) { //num已有点数，sum已耗能量
			break;
		} else {
			sum = sum + num * (a[i] - a[ i - 1]);
			num++;
		}
	}
	l = 1, r = num;
	while (r < n) {
		if (sum + num * (a[r + 1] - a[r] ) > m) {
			ans = max(num, ans);
			l++;
			sum -= a[r] - a[l];
			num--;
		} else {
			r++;
			sum += num * (a[r] - a[r - 1]);
			num++;
		}
	}
	ans = max(ans, num);
	cout << ans;
	return 0;
}