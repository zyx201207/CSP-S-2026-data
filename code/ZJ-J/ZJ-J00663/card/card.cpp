#include <bits/stdc++.h>

using namespace std;

int a[500010], n, m;
int lst[200010], ans[200010];

int main( ) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k <= m; ++k) lst[k] = 0;
		for (int j = i; j <= n; ++j) {
			if (lst[a[j]]) for (int k = lst[a[j]]; k <= j; ++k) lst[a[k]] = 0;
			lst[a[j]] = j;
		}
		for (int j = 1; j <= m; ++j)
			if (lst[j]) ans[j]++;
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';

	return 0;
}
