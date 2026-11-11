#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 500010, M = 300010;
int n, m, a[N], pos[M], ans[M];

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int p = i;
		while(p <= n) {
			ans[a[p]]++;
			p = pos[a[p]] + 1;
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
