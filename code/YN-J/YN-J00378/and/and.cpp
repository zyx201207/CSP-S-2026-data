#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
long long a[maxn];



int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	printf("%d", a[n - m + 1]);

	return 0;
}