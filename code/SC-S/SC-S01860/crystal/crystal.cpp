#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

using namespace std;

constexpr ll MAXN = 5e5 + 5;

int n, m, ans, a[MAXN], pre[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];

	for (int l = 1, r = 1; r <= n; ++r) {
		while (((r - l) * a[r]) - (pre[r - 1] - pre[l - 1]) > m) {
			++l;
		}

		ans = max(ans, r - l + 1);
	}

	cout << ans << '\n';

	return 0;
}