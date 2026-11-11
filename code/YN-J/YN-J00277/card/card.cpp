#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, m, a[N], ans[N];
bool vis[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		deque<int> q;
		memset(vis, 0, sizeof vis);
		for (int j = i; j <= n; j++) {
			if (!vis[a[j]]) {
				vis[a[j]] = true;
				q.push_back(a[j]);
			} else {
				while (1) {
					if (q.back() != a[j]) {
						vis[q.back()] = false;
						q.pop_back();
					} else {
						break;
					}
				}
			}
		}
		for (int j = 1; j <= m; j++) {
			if (vis[j]) {
				ans[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}