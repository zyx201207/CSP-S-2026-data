#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 10;
long long n, m, a[maxn];
int cnt;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 0; i--) {
		cnt++;
		if (cnt == m) {
			printf("%lld", a[i]);
			return 0;
		}
	}
	return 0;
}