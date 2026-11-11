#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, m, a[N], ans = 1, l = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	sort(a + 1, a + 1 + n);
	for (int r = 2; r <= n; r++) {
		m -= (a[r] - a[r - 1]) * (r - l);
		while (m < 0 && l < r) {
			m += a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	printf("%lld", ans);
	return 0;
}
//15:15:35 签到成功
//吓哭了孩子们，这签到题？
//不兑，只能加啊，这么好~~？
//孩子们线性秒了