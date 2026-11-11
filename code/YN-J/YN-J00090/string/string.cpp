#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2E5 + 10;

struct C {
	ll num;
	char d;
} a[N];
int n;
ll ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %c", &a[i].num, &a[i].d);
	int l = 1, r = n;
	ans = 0;
	while (l < r) {
		ll Min = min(a[l].num, a[r].num);
		a[l].num -= Min, a[r].num -= Min;
		if (a[l].d != a[r].d)
			ans += Min;
		if (a[l].num == 0)
			l++;
		if (a[r].num == 0)
			r--;
	}
	printf("%lld\n", ans);
	return 0;
}