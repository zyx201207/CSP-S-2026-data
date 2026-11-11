#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], summ = 0, ans = 1, del;
signed flag = 0;

void dp(int x, int y) {

	if (x == 0 || y > n - 1) {
		return ;
	}

	if (x / ans < a[flag + 1] - a[flag] ) {
		return;
	}
	a[y] += 1;
	int cnt = 1, tmp = a[y], tmp2 = a[y + 1];

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i - 1]) {
			cnt++;
		} else {
			ans =  max(ans, cnt );
			flag = i;
			cnt = 1;
		}
	}
	sort(a, a + n - 1);
	if (a[0] == a[n - 1])
		return ;

	dp(x - 1, y);
	a[y] = tmp - 1;
	dp(x, y + 1);
	a[y + 1] = tmp2 ;

}

signed main() {

	freopen("crystal1.in", "r", stdin);
	freopen("crystal1.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		summ += a[i];
	}

	sort(a, a + n - 1);
	if (summ == (a[0] + a[n - 1])*n / 2) {
		del = a[1] - a[0];
		ans = (del + sqrt(del * del + 8 * del * m)) / (2 * del);
		cout << ans;
		return 0;
	}
	dp(m, 0);
	cout << ans ;
	return 0;
}
