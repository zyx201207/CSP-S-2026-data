#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m;
ll a[N];
ll s[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[i] * mid - (s[i] - s[i - mid]) <= m) {
				ans = max(ans, mid);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}