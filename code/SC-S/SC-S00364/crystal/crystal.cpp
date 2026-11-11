#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 5;
int n, ans, dp, x, y;
long long m, a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);	
	sort(a + 1, a + n + 1);
	
	dp = 0, x = y = 1;
	while (x <= n && y <= n) {
		while (dp + (y - x + 1) * (a[y + 1] - a[y]) <= m && y + 1 <= n) dp += (y - x + 1) * (a[y + 1] - a[y]), y++;
		ans = max(y - x + 1, ans);
		dp -= (a[y] - a[x]), x++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}