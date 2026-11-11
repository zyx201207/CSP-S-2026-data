#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN];
int bit[MAXN];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 19; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1) {
				cnt++;
			}
		}
		if (cnt < m) {
			for (int j = 1; j <= n; j++) {
				a[j] &= ((1 << i) - 1);
			}
		}
	}
	sort(a + 1, a + n + 1);
	int ans = a[n];
	for (int i = n - 1; i >= n - m + 1; i--) ans &= a[i];
	printf("%d", ans);
	return 0;
}

