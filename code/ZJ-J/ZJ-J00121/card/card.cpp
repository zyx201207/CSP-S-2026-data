#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
bool f[M];
int a[N], x[M], ans[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 500) {
		for (int i = 1; i <= n; i++) {
			memset(f, false, sizeof f);
			for (int j = i; j <= n; j++) {
				if (!f[a[j]]) {
					f[a[j]] = true;
					x[a[j]] = j;
				} else {
					for (int k = x[a[j]] + 1; k < j; k++)
						f[a[k]] = false;
					x[a[j]] = j;
				}
			}
			for (int i = 1; i <= m; i++)
				ans[i] += f[i];
		}
		for (int i = 1; i <= m; i++)
			cout << ans[i] << ' ';
		return 0;
	}
	for (int i = 1; i <= n; i++)
		ans[a[i]]++;
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
