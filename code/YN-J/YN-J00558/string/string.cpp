#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf(" %d %c", &a[i], &c[i]);
	int l = 1, r = n;
	while (l < r) {
		if (a[l] >= a[r]) {
			a[l] -= a[r];
			if (c[l] != c[r])
				ans += a[r];
			r--;
		} else {
			a[r] -= a[l];
			if (c[l] != c[r])
				ans += a[l];
			l++;
		}
	}
	printf("%lld", ans);
	return 0;
}