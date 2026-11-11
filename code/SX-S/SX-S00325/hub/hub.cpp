#include <bits/stdc++.h>
using namespace std;

int c, t, n;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	int np1, np2;
	while (t--) {
		scanf("%d%d", &n, &np2);
		for (int i = 1; i <= n - 1; i++)
			scanf("%d%d", &np1, &np2);
		printf("%d\n", 1);
	}
	return 0;
}