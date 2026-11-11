#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
const int N = 5e5+10;
int h[N], dp[N + 10], cha[N];
int t = 0;
bool f1 = 1, f2 = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] != i)
			f2 = 0;
	}
	sort(h + 1, h + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (h[i] - h[i - 1] != ch)
			f1 = 0;
		cha[i] = cha[i - 1] + h[i] - h[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (cha[j] - cha[i] <= m) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}

