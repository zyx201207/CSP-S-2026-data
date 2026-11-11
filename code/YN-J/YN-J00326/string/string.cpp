#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, ans, sum, sum1;
int a[N];
char ch[N];
string s;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> ch[i];
		//	ans += a[i];
	}
	int l = 1, r = n;
	while (l <= r) {
		//	cout << l << " " << r << "\n";
		if (ch[l] != ch[r]) {
			if (a[l] <= a[r]) {
				sum += a[l];
				a[r] -= a[l];
				l++;
			} else if (a[r] < a[l]) {
				sum += a[r];
				a[l] -= a[r];
				r--;
			}
		} else {
			if (a[l] <= a[r]) {
				a[r] -= a[l];
				l++;
			} else if (a[r] < a[l]) {
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << sum;
	return 0;
}
