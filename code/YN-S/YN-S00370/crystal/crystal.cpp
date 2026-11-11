#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, a[10010], b = 0, c = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b = b + a[i];
	}
	sort(a, a + n );
	b = b + m;
	for (int i = n; i >= 1; i--) {
		c = 0;
		for (int j = 1; j < i; j++) {
			c = c + ( a[i] - a[j]);
		}
		printf("%d ", c);
		if (c == m) {
			printf("%d ", i);
			break;
		}
		b = b - a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}