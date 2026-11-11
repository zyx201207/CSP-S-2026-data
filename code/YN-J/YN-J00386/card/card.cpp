#include <iostream>
#include <algorithm>
const int N = 500010, M = 300010;
int a[N], ans[M], nxt[N], vis[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (!vis[a[i]]) {
			vis[a[i]] = i;
		} else {
			nxt[vis[a[i]]] = i;
			vis[a[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		ans[a[j]]++;
		while (j <= n) {
			if (nxt[j]) {
				j = nxt[j];
			} else {
				j++;
				if (j > n)
					break;
				ans[a[j]]++;
			}
		}

	}
	for (int i = 1; i <= m; i++)
		std::cout << ans[i] << " ";
	return 0;
}
