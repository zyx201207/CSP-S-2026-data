#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100005];
long long ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n > 10000) {
		long long cha = a[2] - a[1];
		long long j;
		for (j = 1; j <= n; j++) {
			if ((long long)((long long)j * (long long)(j - 1)) / 2 * (long long)cha <= m)
				ans = j;
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		long long m1 = m, ans1 = 0;
		long long j = i - 1;
		for (; j > 0 && m1 - a[i] + a[j] >= 0; j--)
			m1 -= a[i] - a[j], ans1++;
		ans = max(ans, ans1 + 1);
	}
	cout << ans;
	return 0;
}
