#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n;
long long a[MAXN], b[MAXN];
long long m, ans = 0, minn = 1e18;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
		int le = 1, r = i;
		while (le <= r) {
			int M = (le + r) >> 1;
			long long val = a[i] * (i - M + 1) - (b[i] - b[M - 1]);
			//cout << le << " " << r << " " << M << " " << i << " " << val << "\n";
			if (val > m) {
				le = M + 1;
			} else {
				ans = max(ans, 1ll * i - M + 1);
				r = M - 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
//终于调出来了
//饿啊~