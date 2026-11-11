#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long d[N];
long long s[5010][5010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	long long mx = 0;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		long long h = abs(a[i]);
		mx = max(mx, h);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	long long k = 0;

	if (n <= 5000) {
		long long y = 1;
		for (int i = 2; i <= n; i++) {
			y = 0;
			for (int j = i; j <= n; j++) {
				y++;
				s[i][j] = s[i][j - 1] + d[j] * y;
				if (s[i][j] <= m) {
					k = max(k, 1ll * (j - i + 2));
				} else
					break;
			}
		}
		cout << k;
	} else {
		long long p = a[2] - a[1];
		long long l = 0, su = 0;
		while (su < m) {
			k++;
			l += p;
			su += l;
			if (su > m) {
				k--;
				break;
			}
		}
		cout << k + 1;
	}
	return 0;
}