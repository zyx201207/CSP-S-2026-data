#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[500005];
bool vis[500005];
vector<pair<int, int>> desktop;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		desktop.clear();
		memset(vis, 0, sizeof(vis));
		for (int j = i; j <= n; ++j) {
			if (!vis[j]) {
				for (int k = 0; k < desktop.size(); ++k) {
					if (desktop[k].first == a[j]) {
						for (int l = k; l <= desktop.size(); ++l) {
							vis[desktop[l].second] = true;
							desktop.pop_back();
						}
						break;
					}
				}
				desktop.push_back({a[j], j});
			}
		}
		set<int> c;
		for (pair<int, int> j : desktop) {
			c.insert(j.first);
		}
		for (int j : c) {
			++cnt[j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d ", cnt[i]);
	}
	return 0;
}
