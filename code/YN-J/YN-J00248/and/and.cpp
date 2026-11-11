#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
long long ans = -1e18;

void f(int step, int x, int id) {
	if (step == m) {
		ans = max(ans, 1LL * x);
		return ;
	}
	for (int i = step; i <= n; ++i) {
		if (i == id)
			continue;
		int nx = x & a[i];
		f(step + 1, nx, i);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= (n - m + 1); ++i) {
		f(1, a[i], i);
	}
	printf("%d", ans);
	return 0;
}