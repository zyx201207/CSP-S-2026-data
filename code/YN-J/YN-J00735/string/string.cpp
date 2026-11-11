#include <bits/stdc++.h>
using namespace std;
int a[200000];
char c[20000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	bool flag = 0;
	for (int i = 2; i <= n; i++) {
		if (c[i - 1] != c[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << '0';
		return 0;
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		if (c[l] == c[r]) {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else {
				l++;
				r--;
			}
		} else {
			ans += min(a[l], a[r]);
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[r] > a[l]) {
				a[r] -= a[l];
				l++;
			} else {
				l++;
				r--;
			}
		}
	}
	cout << ans;
}