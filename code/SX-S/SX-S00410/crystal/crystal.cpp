#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	a[0] = a[1];
	int maxl = 0, l = 1, mm = 0, k = 0;
	for (int i = 1; i <= n; i++) {
		mm += (a[i] - a[i - 1]) * k;
		k++;
		while (mm > m) {
			mm -= a[i] - a[l];
			l++;
			k--;
		}
		maxl = max(maxl, k);
	}
	printf("%d", maxl);
	return 0;
}//15.14 100->??
