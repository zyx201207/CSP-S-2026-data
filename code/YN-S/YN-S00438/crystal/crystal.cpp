#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, flag = 1;
int a[N], b[N];

bool check(int mid) {
	for (int i = 1; i <= n - mid + 1; i++) {
		int sum = 0;
		for (int j = i; j <= i + mid - 1; j++) {
			sum += abs(a[j] - a[i + mid - 1]);
			if (sum > m)
				continue;
		}
		if (sum <= m) {
			return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int pd = a[2] - a[1], pd2 = 0;
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != pd) {
			flag = 0;
			break;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		pd2 += abs(a[i] - a[n]);
	if (m >= pd2)
		cout << n;
	else {
		if (pd) {
			int cnt = 0, now = 1;
			for (int i = 1; i <= n; i++) {
				b[i] = b[i - 1] + a[i];
			}
			while (a[now]*now - b[now] <= m) {
				cnt++;
				now++;
			}
			cout << cnt;
		} else {
			int l = 1, r = n, ans = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (check(mid)) {
					l = mid + 1;
					ans = mid;
				} else {
					r = mid - 1;
				}
			}
			cout << ans;
		}
	}
	return 0;
}