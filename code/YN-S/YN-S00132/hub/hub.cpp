#include <iostream>
using namespace std;

int c, t, n, k, a, b;

int main() {

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	scanf("%d %d", &c, &t);

	while (t--) {
		scanf("%d %d", &n, &k);
		printf("%d\n", min(n, k));
		for (int i = 1; i <= max(n, k); ++i)
			scanf("%d %d", &a, &b);
	}

	return 0;
}