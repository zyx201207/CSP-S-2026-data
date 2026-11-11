#include <bits/stdc++.h>
int n;
long long m, a[524288], sa[524288];
bool check(int c) {
	for(int i = c; i <= n; i++)
		if(a[i] * c - sa[i] + sa[i - c] <= m)
			return true;
	return false;
}
int main() {
	freopen("crystal.in", "rb", stdin);
	freopen("crystal.out", "wb", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sa[i] = sa[i - 1] + a[i];
	int l = 1, r = n + 1;
	while(l + 1 < r) {
		int mid = l + r >> 1;
		(check(mid) ? l : r) = mid;
	}
	printf("%d\n", l);
	return 0;
}

