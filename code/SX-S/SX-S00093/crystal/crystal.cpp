#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, m, st = 1, en = 1, s = 0, ans = 1;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	while (st <= en) {
		en++;
		if (en > n) {
			break;
		}
		s = s + (a[en] - a[en - 1]) * (en - st);
		if (s > m) {
			st++;
			s = s - a[en] + a[st - 1];
		}
		ans = max(ans, en - st + 1);
	}
	cout << ans;
	return 0;
}
