#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
int n, m, a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int w = 1 << 30, ans = 0, r = n;
	while (w) {
		sort(a + 1, a + r + 1, [&] (const int &x, const int &y) {
			if ((x & w) != (y & w))
				return (x & w) > (y & w);
			return x > y;
		});
		int pre = r; r = 0;
		for (int i = 1; i <= pre; i++) {
			if (a[i] & w) r = i;
			else break;
		}
		if (r < m) r = pre;
		else ans += w;
		w >>= 1;
	}
	printf("%d\n", ans);
	return 0;
}
