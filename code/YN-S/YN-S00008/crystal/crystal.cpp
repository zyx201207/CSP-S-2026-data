#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

inline ll read() {
	ll num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXN = 5e5 + 8;

ll n, m, a[MAXN], pfx[MAXN];

ll calc(int l, int r) {
	return 1ll * (r - l + 1) * a[r + 1] - (pfx[r] - pfx[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		pfx[i] = pfx[i - 1] + a[i];
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int l = 0, r = i - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (calc(mid, i - 1) <= m)
				r = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;

	return 0;
}