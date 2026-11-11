#include <iostream>
#include <math.h>
#define int long long
using namespace std;
int b[200010][50], a[200010], n, maxl, cnt[50], ans, m;
bool flag[200010];
int f(int id, int v) {
	int i = 0;
	while (v) {
		b[id][++i] = v % 2;
		v /= 2;
		cnt[i] += b[id][i];
	}
	return i;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int len = max(i, f(i, a[i]));
		maxl = max(maxl, len);
	}
	maxl ++;
	while(maxl--) {
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (!flag[i] && b[i][maxl])
				c++;
		}
		if (c >= m) {
			for (int i = 1; i <= n; i++)
				if (!b[i][maxl])
					flag[i] = 1;
			ans += pow(2, maxl - 1);
		}
	}
	cout << ans;
	return 0;
}
