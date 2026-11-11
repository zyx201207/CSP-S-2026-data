#include <bits/stdc++.h>
using namespace std;
const int N = 5E5 + 10;
int n, m, a[N];
int maxr[N], mr[N]; //最后、次后
int ans[N];

struct node {
	int l, r;
} L[N];
int id = 0;
int p[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--) {
		if (maxr[a[i]] == 0)
			maxr[a[i]] = i;
		else
			mr[a[i]] = max(mr[a[i]], i);
	}
	for (int i = 1; i <= n; i++) {
		if (p[a[i]])
			continue;
		p[a[i]] = 1;
		id++;
		L[id].l = i, L[id].r = maxr[a[i]];
		i = maxr[a[i]];
	}
	id++;
	L[id].l = n, L[id].r = -1;
	for (int i = 1; i <= id; i++)
		for (int j = L[i].r + 1; j < L[i + 1].l; j++) {
			ans[a[j]] += j;
		}
	for (int i = 1; i <= n; i++) {
		ans[a[i]]++;
		if (i < L[1].l) {
			ans[a[i]] += i;
			continue;
		}
		int l = 0, r = id, u = -1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (L[mid].l <= i && L[mid].r >= i) {
				u = mid;
				break;
			}
			if (L[mid].r < i)
				l = mid;
			else
				r = mid;
		}
		if (u == -1)
			continue;
		if (mr[a[L[u].l]] <= i && a[i] != a[L[u].l])
			ans[a[i]] += (i - mr[a[L[u].l]] == 1 ? 0 : i - mr[a[L[u].l]]);
	}
	memset(p, 0, sizeof(p));
	ans[a[n]] = n;
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}