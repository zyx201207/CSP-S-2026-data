#include <iostream>
#include <algorithm>
using namespace std;

const int M = 5e5 + 10;
int n, m, x, ans;
int y[M];

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &y[i]);

	sort(y + 1, y + n + 1);
	x = y[(n + 1) / 2];

	for (int i = 1; i <= n; ++i)
		y[i] = abs(y[i] - x);

	sort(y + 1, y + n + 1);

	while (m)
		m -= y[++ans];

	printf("%d", ans);

	return 0;
}