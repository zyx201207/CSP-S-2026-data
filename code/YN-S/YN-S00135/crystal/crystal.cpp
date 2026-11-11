#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, ans = 1, a[N], sum[N], pre, cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cnt = 1;
	sum[1] = a[1];
	pre = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] == pre) {
			cnt++;
		} else {
			//cout << cnt << endl;
			ans = max(ans, cnt);
			cnt = 1;
			pre = a[i];
		}
		sum[i] += a[i] + sum[i - 1];
	}
	ans = max(ans, cnt);
	//cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j > 0; j--) {
			if (sum[i] - sum[j - 1] + m >= (i - j + 1) * a[i]) {
				cnt = max((ll)i - j + 1, cnt);
			}
		}

	}
	ans = max(cnt, ans);
	cout << ans << endl;
	return 0;
}