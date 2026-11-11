#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
#define int long long
int n, m, a[N], sum, min1 = 1e18, ll = 1, rr = 1, cnt = 1, x, f, flag1 = 1, flag2 = 1;


//数据大时怎么找众数？
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			flag1 = 0;
		}
		sum += a[i];
	}
	for (int i = 2; i < n; i++) {
		if ((a[i] - a[i - 1]) != (a[i + 1] - a[i])) {
			flag2 = 0;
		}
	}
	if (flag1 == 1) {
		cout << (int) (-1 + sqrt(1 + 8 * sum)) / 2;
		return 0;
	}
	if (flag2 == 1) {
		cout << (int)(-a[1] + sqrt(a[1]*a[1] + 8 * sum)) / 2;
		return 0;
	}
	int s = sum / n;
	sort(a + 1, a + n + 1);
	a[0] = -1e18-5;
	int mid = (n + 1) / 2;
	//int c = a[(n + 1) / 2]; //中位数to? 注意到m<=1e1
	//找最接近平均数的
	for (int i = 1; i <= n; i++) {
		if (abs(a[i] - s) <= min1) {
			x = i;
			min1 = abs(a[i] - s);
		}
	}
	while (m > 0) {
		int l = abs(a[mid - ll] - a[mid]), r = abs(a[mid + rr] - a[mid]) * cnt;
		if (l <= r) {
			m -= l;
			ll++;
			cnt ++ ;
		} else {
			m -= r;
			if (m <= 0) {
				break;
			}
			a[mid] = a[mid + rr];
			rr++;
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}