#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+7;
int n, a[N], m, aa[10000000], b[N], c[N], ans = -1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		aa[a[i]]++;
	for (int i = 1; i <= n; i++)
		ans = max(ans, aa[i]);
	for (int i = 2; i <= n; i++) {
		b[i - 1] += a[i] - a[i - 1];
	}
	c[1] = b[1];
	for (int i = 2; i <= n; i++) {
		c[i] = b[i] * i + c[i - 1];
	}
	/*for (int i = 1; i < n; i++)
		cout << b[i] << " ";
	cout << '\n';
	for (int i = 1; i < n; i++)
		cout << c[i] << " ";
	cout << '\n';*/
	int sum = 0;
	for (int i = n - 1 ; i >= 1; i--) {
		if (m < c[i] && m >= c[i - 1]) {
			sum = i  ;
			break;
		}
	}
	if (m >= c[n - 1])
		sum = n;
	cout << max(ans, sum);
	return 0;
}