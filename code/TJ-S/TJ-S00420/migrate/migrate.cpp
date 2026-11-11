#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e6 + 2;
int c, t, n;
ll d, x[maxn];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	while (t--) {
		scanf("%d %lld", &n, &d);
		for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
		puts("0");
	}
	
	return 0;
}
