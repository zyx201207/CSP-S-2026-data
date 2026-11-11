#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Init ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const int N = 5e5 + 5;
int n, ans = 1, j = 1;
ll m, a[N], sum[N];

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 2; i <= n; i++) {
		ll cur = (i - j) * a[i] - sum[i - 1] + sum[j - 1];
		while (cur > m) {
			cur -= a[i];
			cur += a[j];
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}