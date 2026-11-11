#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
string s = " ";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	for (int i = 1, j = n; i <= j;) {
		if (c[i] != c[j]) {
			ans += min(a[i], a[j]);
			if (a[i] != a[j]) {
				if (a[i] > a[j]) {
					a[i] -= a[j];
					j--;
				} else {
					a[j] -= a[i];
					i++;
				}
			} else {
				i++;
				j--;
				continue;
			}
		} else {
			if (a[i] != a[j]) {
				if (a[i] > a[j]) {
					a[i] -= a[j];
					j--;
				} else {
					a[j] -= a[i];
					i++;
				}
			} else {
				i++;
				j--;
				continue;
			}
		}
	}
	cout << ans;
	return 0;
}