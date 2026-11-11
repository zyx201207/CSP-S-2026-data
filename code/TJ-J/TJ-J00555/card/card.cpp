/*

	rating: 1700
	good

*/

#include <bits/stdc++.h>

int n, m, a[500005], c[300005], ans[300005], last[300005], size[500005];
std::vector<int> ver[500005];

void dfs1(int x) {
	size[x] = 1;
	for (int i = 0; i < ver[x].size(); ++i) {
		int y = ver[x][i];
		dfs1(y);
		size[x] += size[y];
	}
	return ;
}

void dfs2(int x) {
	c[a[x]] += 1;
	if (c[a[x]] == 1) {
		ans[a[x]] += size[x];
	}
	for (int i = 0; i < ver[x].size(); ++i) {
		int y = ver[x][i];
		dfs2(y);
	}
	c[a[x]] -= 1;
	return ;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; --i) {
		if (last[a[i]] != 0) {
			ver[last[a[i]]].push_back(i);
		} else if (i < n) {
			ver[i + 1].push_back(i);
		}
		last[a[i]] = i;
	}
	dfs1(n);
	dfs2(n);
	for (int i = 1; i <= m; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
