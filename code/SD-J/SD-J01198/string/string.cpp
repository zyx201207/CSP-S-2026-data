#include <bits/stdc++.h>
using namespace std;

long long n, a[200005];
char s[200005], cas[2000005];

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> s[i];
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) cas[++cnt] = s[i];
	}
	long long l = 1, r = cnt, ans = 0;
	while (l < r) {
		if (cas[l] != cas[r]) ans++;
		l++;
		r--;
	}
	cout << ans << "\n";
	return 0;
}
