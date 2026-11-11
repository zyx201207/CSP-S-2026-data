#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
using ll = long long;
ll m, a[maxn], sum, ans;
int n, cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll i = 1, j = 1;
	while (j <= n) {
		sum += (a[j] - a[j - 1]) * (j - i);
		while (sum > m && i <= j) {
			i++;
			sum -= (a[j] - a[i - 1]);
		}
		ans = max(ans, j - i + 1);
		j++;
	}
	cout << ans << '\n';
	return 0;
}