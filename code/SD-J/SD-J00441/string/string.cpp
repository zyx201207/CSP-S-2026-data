#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long n, a1[MAXN], a2[MAXN];
char c1[MAXN], c2[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i] >> c1[i];
		a2[n - i + 1] = a1[i];
		c2[n - i + 1] = c1[i];
	}
	long long ans = 0, cnt1 = a1[1], cnt2 = a2[1], i = 1, j = 1;
	while (i <= n && j <= n) {
		long long tmp = min(cnt1, cnt2);
		cnt1 -= tmp, cnt2 -= tmp;
		if (c1[i] != c2[j]) ans += tmp;
		if (cnt1 <= cnt2) i++, cnt1 += a1[i];
		else j++, cnt2 += a2[j];
	}
	cout << ans / 2 << '\n';
	return 0;																																																																													
} 
