#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int)5e5 + 11;
int n, ans;
ll m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[n] - a[i];
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i;
		while (L + 1 < R) {
			int M = (L + R) >> 1;
			if (s[i] - s[M - 1] - (1LL + i - M) * (a[n] - a[i]) <= m)
				R = M;
			else
				L = M;
		}
		ans = max(ans, i - R + 1);
	}
	printf("%d\n", ans);
	return 0;
}
