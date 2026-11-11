#include <bits/stdc++.h>
using namespace std;
//¶þ·Ö
int n;
long long m, a[500010], s[500010];
int ans;

int solve(long long x, int st, int ed) {
	int cur = 0, l = st, r = ed;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (x * (mid - st + 1) - (s[mid] - s[st - 1]) <= m) {
			cur = mid - st + 1;
			l = mid + 1;
		} else
			r = mid;
	}
	if (cur < l - st + 1)
		if (x * (l - st + 1) - (s[l] - s[st - 1]) <= m)
			return cur + 1;
	return cur;
}

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i < n; ++i)
		ans = max(ans, 1 + solve(a[i], i + 1, n));
	cout << ans;
	return 0;
}