#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[300005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		queue<int>q;
		int vis[300005];

		for (int j = i; j <= n; j++) {

			if (vis[a[j]] == 0) {
				vis[a[j]]++;
				q.push(a[j]);
			} else {
				queue<int>xuyao;
				int pd = 0;

				while (!q.empty()) {
					if (q.front() != a[j] && pd == 0) {
						xuyao.push(q.front());
					} else {
						pd = 1;
					}

					vis[q.front()]--;
					q.pop();
				}

				while (!xuyao.empty()) {
					q.push(xuyao.front());
					xuyao.pop();
				}

				vis[a[j]]++;
				q.push(a[j]);
			}

		}

		while (!q.empty()) {
			ans[q.front()]++;
			q.pop();
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << ' ';
	}

	return 0;
}