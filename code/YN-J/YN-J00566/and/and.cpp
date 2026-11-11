#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[10010];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", a[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}