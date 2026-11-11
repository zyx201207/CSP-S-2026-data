#include <iostream>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int y[N], q[M], ans[M];

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &y[i]);
	}

	for (int i = 1; i <= n; ++i) {

		int p = 1;
		memset(q, 0, sizeof(q));

		for (int j = i; j <= n; ++j) {

			if (q[j]) {
				p = q[y[j]];
				for (int o = 1; o <= m; ++o)
					if (q[o] > q[j])
						q[o] = 0;
			}

			q[j] = p++;

		}

		for (int j = 1; j <= m; ++j)
			ans[y[j]] += q[y[j]];
	}

	for (int i = 1; i <= m; ++i)
		printf("%d ", ans[i]);

	return 0;
}