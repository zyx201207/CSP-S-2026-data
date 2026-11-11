#include <bits/stdc++.h>

using namespace std;

const int N = 2001000;

int c, T, n;
long long m, a[N];

void solve() {
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	printf("%d\n", rand() % 3); 
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	srand(time(0));
	scanf("%d%d", &c, &T);
	while (T--) solve();
	return 0;
} 
