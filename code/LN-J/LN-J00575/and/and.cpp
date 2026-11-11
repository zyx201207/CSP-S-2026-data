#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans;
int a[N];
bool st[N];
int cnt;
void dfs(int u, int c) {
	if (u > m) {
		int tmp = -1;
		++cnt;
		for (int i = 1; i <= n; ++i) {
			if (st[i]) tmp &= a[i];
		}
		ans = max(ans, tmp);
		return;
	}
	if (u - m > n - c) return;
	for (int i = c; i <= n; ++i) {
		if (st[i]) continue;
		st[i] = true;
		dfs(u + 1, i + 1);
		st[i] = false;
		// dfs(u + 1, c);
	}
	return;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}
