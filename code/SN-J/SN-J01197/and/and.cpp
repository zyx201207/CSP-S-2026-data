#include <bits/stdc++.h>
using namespace std;

int n ,m;
int a[100067];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int ans = 0, x = a[n];
	for (int i = 1; i <= n - 1; i ++) {
		ans = max(ans, x & n);
	}
	printf("%d\n", ans);
	return 0;
}
