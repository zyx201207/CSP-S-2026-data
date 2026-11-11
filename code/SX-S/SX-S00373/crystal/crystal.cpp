#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5+3;
LL n, m, a[N], chazhi, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i++) {
		chazhi += (i - j) * (a[i] - a[i - 1]);
		if (m >= chazhi)
			ans = max(ans, (LL)(i - j + 1));
		else
			while (m < chazhi)
				chazhi -= (a[i] - a[j]), j++;
	}
	cout << ans;
	return 0;
}