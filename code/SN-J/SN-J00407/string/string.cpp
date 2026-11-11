#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %c", &a[i], &c[i]);
	int l = 1, r = n;
	ll ans = 0;
	while (l < r) {
		int x = min(a[l], a[r]);
		a[l] -= x, a[r] -= x;
		if (c[l] != c[r]) ans += x;
		if (!a[l]) l++;
		if (!a[r]) r--;
	}
	printf("%lld", ans);
}

