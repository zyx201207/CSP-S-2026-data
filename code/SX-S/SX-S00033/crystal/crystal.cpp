#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m, ans;
int a[N], sum[N], sumc[N];
int b[N];

signed main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	stable_sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		b[i] = a[n] - a[i];
	}
	for (int i = n; i >= 1; i--)
		sumc[i] = sumc[i + 1] + b[i];
	for (int i = n; i >= 1; i--) {
		for (int j = 1; i - j >= 1; j++) {
			int x = sumc[i - j] - sumc[i] - b[i] * j;
			if (x <= m)
				ans = max(ans, j + 1);
			else
				break;
		}
	}
	cout << ans;


	return 0;
}
