#include <bits/stdc++.h>
using namespace std;

struct fu {
	int a;
	char c;
} f[200010], g[200010];
int n;
long long cnt1 = 1, cnt2 = 1, ans;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> f[i].a >> f[i].c;
	}
	for (int i = n; i >= 1; i--) {
		g[i].a = f[n - i + 1].a, g[i].c = f[n - i + 1].c;
	}
	while (cnt1 <= n && cnt2 <= n) {
		if (g[cnt1].a > f[cnt2].a) {
			if (g[cnt1].c != f[cnt2].c) {
				ans += f[cnt2].a;
				g[cnt1].a -= f[cnt2].a;
				f[cnt2].a = 0;
			} else {
				g[cnt1].a -= f[cnt2].a;
				f[cnt2].a = 0;
			}
			cnt2++;
		} else if (g[cnt1].a < f[cnt2].a) {
			if (g[cnt1].c != f[cnt2].c) {
				ans += g[cnt1].a;
				f[cnt2].a -= g[cnt1].a;
				g[cnt1].a = 0;
			} else {
				f[cnt2].a -= g[cnt1].a;
				g[cnt1].a = 0;
			}
			cnt1++;
		} else if (g[cnt1].a = f[cnt2].a) {
			if (g[cnt1].c != f[cnt2].c) {
				ans += f[cnt2].a;
				g[cnt1].a = 0;
				f[cnt2].a = 0;
			} else {
				g[cnt1].a = 0;
				f[cnt2].a = 0;
			}
			cnt1++, cnt2++;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}