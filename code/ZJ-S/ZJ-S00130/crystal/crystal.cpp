#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 500010;
int n;
ll m, a[N], s[N];

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		while(a[i] * 1ll * (i - l + 1) - (s[i] - s[l - 1]) > m)
			++l;
		ans = max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
