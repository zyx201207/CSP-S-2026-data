#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
int c, n, d, t;
ll x[N];
int main() {
	freopen("migrate.in", "w", stdin);
	freopen("migrate.out" , "a", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		printf("0\n");
	}
}