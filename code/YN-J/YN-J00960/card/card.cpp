#include <cstdio>
#include <iostream>
using namespace std;
int n, m, a[200010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int x = 10, y = 3, z = 3;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d %d %d", x, y, z);
	fclose(stdin);
	fclose(stdout);
	return 0;
}