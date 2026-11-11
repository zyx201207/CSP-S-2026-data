#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500010];
int aa[500010];
int p[500010];
int v[300010];
long long ans[300010];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool t = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			t = false;
		}
	}
	if (t) {
		int l = 0;
		int cnt = 0;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (a[j] == a[j - 1] && j != i) {
					continue;
				}
				ans[a[j]]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof(v));
		memset(p, 0, sizeof(p));
		for (int j = i; j <= n; j++) {
			if (v[a[j]] != 0) {
				for (int k = v[a[j]]; k < j; k++) {
					v[p[k]] = 0;
					p[k] = 0;
				}
			}
			v[a[j]] = j;
			p[j] = a[j];
		}
		for (int j = i; j <= n; j++) {
			ans[p[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}
