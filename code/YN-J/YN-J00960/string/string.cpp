#include <cstdio>
#include <iostream>
using namespace std;
long long n, a[200010];
char c[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int ans = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %s", &a[i], c);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}