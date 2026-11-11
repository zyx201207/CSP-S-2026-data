#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;
int n;
ll m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i + 1;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - s[i] + s[mid - 1] <= m) 
				r = mid;
			else 
				l = mid;
		}
		ans = max(ans, i - l);
	}
	printf("%d\n", ans);
}

