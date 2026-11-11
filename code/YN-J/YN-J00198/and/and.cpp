#include <iostream>
using namespace std;

const int M = 2e5 + 10;
int n, m, ans;
int y[M], s[M];
bool q[M];

void dfs(int idx) {

	if (idx > m) {
		int sum = s[1];
		for (int i = 2; i <= m; ++i)
			sum &= s[i];
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (q[i])
			continue;
		q[i] = true;
		s[idx] = y[i];
		dfs(idx + 1);
		q[i] = false;
	}

	return;

}

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &y[i]);
	}

	dfs(1);

	printf("%d", ans);

	return 0;
}