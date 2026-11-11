#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
bool vis[200005];
vector<int> b;
void dfs(int depth) {
	if (depth > m) {
		int now = b[0];
		for (int i = 1; i < b.size(); ++i) {
			now &= b[i];
		}
		ans = max(ans, now);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			b.push_back(a[i]);
			dfs(depth + 1);
			b.pop_back();
			vis[i] = false;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
