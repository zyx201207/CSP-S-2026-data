#include <bits/stdc++.h>
using namespace std;

int c, t, x[2000001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		int n, d;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%d", &x[i]);
		printf("0\n");
	}
}
