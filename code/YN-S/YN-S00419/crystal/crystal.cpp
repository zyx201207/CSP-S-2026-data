#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5 + 10;
int n, m, a[N], ans, res;
bool flag1 = 1, flag = 1;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1] && i != 1)
			flag = 0;
		else if (a[i] - a[i - 1] != a[i - 1] - a[i - 2] && i >= 2)
			flag1 = 0;
	}
	if (flag)
		cout << n;
	else if (flag1) {
		m /= (a[n] - a[n - 1]);
		while (m - ans - 1 >= 0)
			ans++, m -= ans;
		cout << ans + 1;
	} else if (n <= 5000) {
		sort(a + 1, a + 1 + n), ans = 1;
		for (int i = 2; i <= n; i++) {
			res = 1;
			for (int j = i - 1, lose = m; j >= 1 && lose - a[j] >= 0; j--, lose -= a[j])
				res++;
			ans = max(ans, res);
		}
		cout << ans - 1;
	}
	return 0;
}
