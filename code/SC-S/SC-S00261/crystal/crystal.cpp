#include <iostream>
#include <algorithm>
using ll = long long;

const int N = 500005;

int n, ans;
ll m, a[N], s[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for(int i = 1, j = 0; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
		while((i - j) * a[i] - (s[i] - s[j]) > m) ++j;
		ans = std::max(ans, i - j); 
	}
	printf("%d\n", ans);
}