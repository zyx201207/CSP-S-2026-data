#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], m, ans = -0x3f3f3f3f;
bool vis[200005];

void dfs(int pos, long long cnt) {
	if (pos == m + 1) {
		ans = max(ans, cnt);
		return;
	}
	if (cnt <= ans)
		return;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = true;
		dfs(pos + 1, cnt & a[i]);
		vis[i] = false;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a[i]);
	for (int i = 1; i <= n; i++) {
		vis[i] = true;
		dfs(2, a[i]);
		vis[i] = false;
	}
	printf("%lld", ans);
	return 0;
}