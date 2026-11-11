#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
long long a[N], s[N];
long long m;

bool check(int l, int r) {
	if (a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m)
		return true;
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ ) {
		s[i] = s[i - 1] + a[i];
	}
	int j = 1, mx = 0;
	for (int i = 1; i <= n; i ++ ) {
		while (j <= i && !check(j, i)) {
			j ++ ;
		}
		mx = max(mx, i - j + 1);
	}
	printf("%d\n", mx);
	return 0;
} 
