#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, a[500005], mx, cnt, sum, flag;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum = m;
	cnt = 1;
	for (int j = 1; j < n; j++) {
		if (sum < cnt * (a[j + 1] - a[j])) {
			break;
		}
		sum -= cnt * (a[j + 1] - a[j]);
		cnt++;
		mx = max(cnt, mx);
	}
	for (int i = 2; i <= n; i++) {
		cnt--;
		sum += a[i + cnt - 1] - a[i - 1];
		for (int j = i + cnt-1 ; j < n; j++) {
			if (sum < cnt * (a[j + 1] - a[j])) {
				break;
			}
			sum -= cnt * (a[j + 1] - a[j]);
			cnt++;
			mx = max(cnt, mx);
		}
	}
	cout << mx << endl;
	return 0;
}