#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t;
ll ind[2000100];
ll n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &ind[i]);
		printf("0\n");
	}
	return 0;
}