#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[250000], l = 0, ans = 0;
	char c[250000], s[1000000];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	for (int i = 1; i <= n; i++) l += a[i];
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= a[i]; k++){
				s[i] = c[j];
			}
		}
	}
	for (int i = 1; i <= l; i++) {
		if (s[i] != s[l + 1 - i]) {
			ans += 1;
		}
	}
	ans /= 2;
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
