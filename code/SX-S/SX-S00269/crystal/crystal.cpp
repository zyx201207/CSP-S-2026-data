#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500007], s[500007];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool f = 0;
	for (int i = 1; i < n; i++) {
		s[i] = a[i + 1] - a[i];
		if (i != 1 && s[i] != s[i - 1])
			f = 1;
	}
	if (!f) {
		long long sum = 0;
		int ans = -1;
		for (int i = 1; i < n; i++) {
			if (sum + s[i]*i <= m) {
				sum += s[i] * i;
			} else {
				ans = i;
				break;
			}
		}
		if (ans == -1)
			cout << n;
		else {
			cout << ans;
		}
		return 0;
	}
	int ans = -1;
	for (int j = 1; j < n; j++) {
		long long sum = 0;
		int cnt = 0;
		for (int i = j; i <= n; i++) {
			cnt++;
			if (sum + s[i]*cnt <= m) {
				sum += s[i] * cnt;
			} else {
				break;
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}
