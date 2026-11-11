#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 2500;
int n;
long long a[maxn], ans;
char c[maxn];

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%d", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i], &c[i]);
	}
	int i = 1;
	while (i != n - i + 1) {
		if (a[i] <= a[n - i + 1]) {
			if (c[i] != c[n - i + 1])
				ans += a[i];
			a[n - i + 1] -= a[i];
			i++;
			n++;
		} else {
			if (c[i] != c[n - i + 1])
				ans += a[n - i + 1];
			a[i] -= a[n - i + 1];
			n--;
		}
	}
	printf("%lld", ans);

	return 0;
}