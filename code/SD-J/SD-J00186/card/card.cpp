#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul; 
ul n, m;
ul a[500005];
struct kard {
	bool f;
	ul pos;
}vis[500005];
ul ans[300005];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio ();
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n; ++i)
		cin >> a[i];
	for (int i = 1;i <= n; ++i) {
		ul ps = 1;
		for (int j = 0;j <= n; ++j) vis[j].f = false, vis[j].pos = 0;
		for (int j = i;j <= n; ++j) {
			if (!vis[a[j]].f) {
				vis[a[j]].f = true;
				vis[a[j]].pos = ps++;
			}
			else {
				for (int l = 1;l <= m; ++l) {
					if (vis[l].pos >= vis[a[j]].pos && l != a[j] && vis[l].f == true)
						vis[l].f = false, ps--;
				}
				vis[a[j]].f = true;
				vis[a[j]].pos = ps++;
			}
		}
		for (int j = 1;j <= m; ++j) {
			if (vis[j].f)
				ans[j]++;
		}
	}
	for (int i = 1;i <= m; ++i)
		cout << ans[i] << ' ';
	return 0;
} 
//ChatGPT Éú³É 
