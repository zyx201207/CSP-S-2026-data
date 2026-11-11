#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int N = 500005;
int n;
llong m, a[N], s[N];
llong calc(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]); 
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i + 1;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (calc(M, i) <= m)
				R = M;
			else
				L = M; 
		}
		ans = max(ans, i - R + 1);
	}
	printf("%d\n", ans);
	return 0;
} 
