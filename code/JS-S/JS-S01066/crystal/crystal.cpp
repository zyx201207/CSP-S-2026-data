#include <bits/stdc++.h>
#define ll long long
const int N = 5e5 + 10;
using namespace std;

int n, ans;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

	int l = 1;
	for(int i = 2; i <= n; i++) {
		while(l < i && (a[i] * (i - l)) - (sum[i - 1] - sum[l - 1]) > m) l++;
		ans = max(ans, i - l + 1);
	}

	printf("%d", ans);

	return 0;
}
