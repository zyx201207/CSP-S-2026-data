#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int j, ans = 0, maxx = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long M, m;
	scanf("%d%lld", &n, &M);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] != a[i]) {
			r = i - 1;
			j = l - 1;
			ans = r - l + 1;
			l = i;
			m = M;
			while (j > 0) {
				if (m - (a[i - 1] - a[j]) >= 0) {
					m -= (a[i - 1] - a[j]);
					j--;
					ans++;
				} else {
					break;
				}
			}
			maxx = max(maxx, ans);
		}
	}
	printf("%d", maxx);
	return 0;
}
