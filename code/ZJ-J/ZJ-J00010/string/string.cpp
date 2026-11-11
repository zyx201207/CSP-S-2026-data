#include <bits/stdc++.h>
using namespace std;
long long n;
long long k[200005];
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> k[i] >> c[i];
	long long L = 1, Lre = k[1];
	long long R = n, Rre = k[n];
	long long ans = 0;
	while (L < R) {
		long long m = min(Lre, Rre);
		if (c[L] != c[R]) ans += m;
		Lre -= m; Rre -= m;
		if (!Lre) L++, Lre = k[L];
		if (!Rre) R--, Rre = k[R];
	}
	cout << ans << '\n';
	return 0;
}
