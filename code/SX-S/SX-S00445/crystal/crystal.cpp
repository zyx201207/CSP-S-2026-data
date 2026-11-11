#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
long long a[maxn], n,  l = 1, ans;
long long num,  m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		num += (i - l) * (a[i] - a[i - 1]);
		while (num > m) {
			num -= a[i] - a[l];
			l++;
		}
		if (ans < i - l + 1)
			ans = i - l + 1;
	}
	printf("%lld", ans);
	return 0;
}
