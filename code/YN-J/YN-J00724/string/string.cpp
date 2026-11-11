#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], p = 1, ans = 0, sum = 0;
char c[200005], s[200005];
bool flag;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s[p] = c[i];
			p++;
		}
	}
	int q = p;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	for (int i = 1; i <= sum / 2; i++) {
		if (s[p - 1] != s[i]) {
			ans++;
		}
		if (p > q / 2) {
			p--;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}