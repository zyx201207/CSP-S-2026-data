#include <iostream>
using namespace std;
int c, t, n, k;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1, u, v; i < n; i++) 
			scanf("%d%d", &u, &v);
		printf("%d\n", (n - (k - 1) * 2) / 8);
	}
}