#include <iostream>
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d;
int y[N];

int main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%d %d", &c, &t);

	while (t--) {
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &y[i]);

		printf("%d ", y[d]);
	}

	return 0;
}