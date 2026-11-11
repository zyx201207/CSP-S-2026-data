#include <bits/stdc++.h>
using namespace std;
int a[500010], c[300010];
vector<vector<int> > g(500010);
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		g[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n) {
			j = g[a[j]].back();
			c[a[j]]++;
			j++;
		}
		c[a[j]]++;
	}
	for (int i = 1; i <= m; i++) printf("%d ", c[i]);
	return 0;
}