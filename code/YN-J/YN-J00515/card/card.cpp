#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[5003];
	int ans[5003];
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
		ans[i] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int k = i;
		int f[5003];
		vector<int>q;
		for (int j = 0; j <= m; j++)
			f[j] = 0;
		while (k <= n) {
			if (f[a[k]]) {
				while (!q.empty()) {
					int x = q.back();
					f[x] = 0;
					q.pop_back();
					if (x == a[k])
						break;
				}
			}
			q.push_back(a[k]);
			f[a[k]] = 1;
			k++;
		}
		while (!q.empty()) {
			int x = q.front();
			ans[x]++;
			q.pop_back();
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}