#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, f = 1, ma = 1;

long long m, a[500100] = {0}, c = 0, l = 0, j = 0;

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	if (m == 0) {
		printf("1");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	for (int i = 1; i < n; ++i) {
		if (c + (a[i] - a[i - 1])*f <= m) {
			c += (a[i] - a[i - 1]) * f;
			l += (a[i] - a[i - 1]);
			++f;
			if (ma < i - j + 1) {
				++ma;
			}
		} else {
			c -= l;
			l -= (a[j + 1] - a[j]);
			++j;
			--i;
			--f;
		}
	}
	printf("%d", ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}








