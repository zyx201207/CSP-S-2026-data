#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], vis[N], res[N];
stack<int>stk;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (!stk.empty()) {
					int x = stk.top();
					stk.pop();
					vis[x] = 0;
					if (x == a[j])
						break;
				}
				vis[a[j]] = 1;
				stk.push(a[j]);
			} else {
				vis[a[j]] = 1;
				stk.push(a[j]);
			}
		}
		while (!stk.empty()) {
			int x = stk.top();
			stk.pop();
			res[x]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << res[i] << ' ';
	return 0;
}