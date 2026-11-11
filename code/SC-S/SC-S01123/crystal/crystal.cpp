#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
long long e[maxn], sum, m;
int n, p = 1, ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", e + i);
	sort(e + 1, e + 1 + n);
	for (int i = 2; i <= n; i++) {
		sum += e[i - 1];
		while (e[i] * (i - p) - sum > m) sum -= e[p++];
		ans = max(ans, i - p + 1);
	}
	printf("%d\n", ans);
	return 0;
}