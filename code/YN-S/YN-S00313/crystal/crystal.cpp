#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
long long a[maxn], n;
long long f[maxn], m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[1] = 0;
	long long  ans = 1, s = 1;
	for (long long i = 2; i <= n; i++) {
		long long sum = f[i - 1] + (i - s) * (a[i] - a[i - 1]);
		while (s <= n && sum > m) {
			sum -= (a[i] - a[s++]);
		}
		f[i] = sum;
		ans = max(ans, i - s + 1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}