#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, a[100010], x = -1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > x) {
			x = a[i];
		}
	}
	printf("%d", x);
	fclose(stdin);
	stdout(stdout);
	return 0;
}