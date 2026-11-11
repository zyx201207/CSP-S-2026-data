#include <bits/stdc++.h>
using namespace std;
long long n, m, len, ans, a[500005], b[500005], cnt[500005], cur[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1), len = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++)
		cnt[a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b]++;
	long long s = 0, c = 0;
	for(int i = 1, j = 1; i <= len; i++) {
		s += c * (b[i] - b[i - 1]), c += (cur[i] = cnt[i]);
		while(s - (b[i] - b[j]) * (cur[j] - 1) > m)
			c -= cur[j], s -= (b[i] - b[j]) * cur[j], cur[j++] = 0;
		if(s > m) {
			auto tmp = (s - m + b[i] - b[j] - 1) / (b[i] - b[j]);
			assert(tmp < cur[j]);
			c -= tmp, cur[j] -= tmp, s -= tmp * (b[i] - b[j]);
		}
		ans = max(ans, c);
	}
	cout << ans;
	return 0;
}