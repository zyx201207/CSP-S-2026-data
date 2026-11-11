#include <iostream>
#include <deque>

using namespace std;
int n, m, a[500005], vis[300005], ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= m; i++) {
		deque<int> q;
		for (int j = 1; j <= n; j++) {
			bool flag = false;
			for (int x = j; x <= n; x++) {
				if (!vis[a[x]]) {
					q.push_back(a[x]);
					vis[a[x]] = true;
				} else {
					while (q.back() != a[x]) {
						vis[q.back()] = false;
						q.pop_back();
					}
				}
			}
			while (!q.empty()) {
				if (q.back() == i) flag = true;
				vis[q.back()] = false;
				q.pop_back();
			}
			if (flag) ans[i]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}