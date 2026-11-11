#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n, ans, sum, len[N * 2];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> len[sum + 1] >> c[sum + 1];
		len[sum + len[sum + 1]] = len[sum + 1];
		c[sum + len[sum + 1]] = c[sum + 1];
		sum += len[sum + 1];
	}
	ll rep = 0, last = len[1];
	for (int i = 1; i <= sum / 2; i += rep) {
		len[i] = last - rep;
		rep = min(len[i], len[sum - i + 1]);
		last = max(len[i], len[sum - i + 1]);
		if (c[i] == c[sum - i + 1])
			continue;
		ans += rep;
	}
	cout << ans;
	return 0;
}
