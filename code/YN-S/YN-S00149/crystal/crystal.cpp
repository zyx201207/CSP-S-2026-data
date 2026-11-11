#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[1000005], mx, cnt, ans, num, answer, qwq, hhh, qaq;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], cnt += i;
		if (i == 2)
			qaq = a[i] - a[i - 1];
		answer += qaq * i;
		cout << cnt << ' ' << answer << '\n';
		if (m >= answer)
			qwq = max(qwq, i);
		if (m >= cnt)
			ans = max(ans, i);
		if (a[i] == i)
			num++;
		if (a[i] - a[i - 1] == qaq)
			hhh++;
	}
	if (num == n) {
		cout << ans + 1;
		return 0;
	}
	if (hhh == n - 1) {
		cout << qwq + 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		int b = m, ans = 0;
		for (int j = i; j >= 1; j--) {
			if (b >= a[i] - a[j])
				b -= a[i] - a[j], ans++;
			else
				break;
		}
		mx = max(mx, ans);
	}
	cout << mx;
	return 0;
}