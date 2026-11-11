#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
ll a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		if (n % 2 == 0 && d % 2 == 0) {
			printf("%lld\n", n/2-1);
		} else if (n % 2 == 1 && d % 2 == 0) {
			printf("%lld\n", n/2);
		} else if (n % 2 == 1 && d % 2 == 1) {
			printf("%lld\n", n/2-1);
		} else {
			printf("%lld\n", n/2);
		}
	}
	
	return 0;
}
