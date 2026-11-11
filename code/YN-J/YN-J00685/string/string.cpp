#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 10;
int n, a[N], ans;
char c[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for (int i = 1, j = n; i < j; i++) {
		int k = a[i];
		while (k) {
			if (k >= a[j])
				k -= a[j], ans += a[j] * (c[i] == c[j] ? 0 : 1), j--;
			else
				ans += k * (c[i] == c[j] ? 0 : 1), a[j] -= k, k = 0;
		}
	}
	cout << ans;
	return 0;
}
