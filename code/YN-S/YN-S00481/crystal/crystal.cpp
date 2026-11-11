#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; a[i]*i <= m + a[i]; i++) {
		ans++;
		m += a[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}