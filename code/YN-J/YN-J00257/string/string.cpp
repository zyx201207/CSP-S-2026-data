#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int n;
int a[N];
char b[N];
int ans = 0, sum = 0, ans1 = 0, s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		ans += a[i];
	}
	s = ans;
	ans /= 2;
	for (int i = 1, j = n;;) {
		if (ans1 > ans && s % 2 != 0) {
			break;
		}
		if (ans1 >= ans && s % 2 == 0) {
			break;
		}
//		cout << a[i] << " " << b[i] << " " << a[j] << " " << b[j];
//		cout << endl;
//		cout << i << " " << j << " ";
		if (b[i] != b[j]) {
			sum += min(a[i], a[j]);
			if (a[i] > a[j]) {
				a[i] -= a[j];
				ans1 += a[j];
				j--;
			} else if (a[i] < a[j]) {
				a[j] -= a[i];
				ans1 += a[i];
				i++;
			} else if (a[i] == a[j]) {
				ans1 += a[i];
				i++, j--;
			}
		}
		if (b[i] == b[j]) {
			if (a[i] > a[j]) {
				a[i] -= a[j];
				ans1 += a[j];
				j--;
			} else if (a[i] < a[j]) {
				a[j] -= a[i];
				ans1 += a[i];
				i++;
			} else if (a[i] == a[j]) {
				ans1 += a[i];
				i++, j--;
			}
		}
	}
	cout << sum;
	return 0;
}
