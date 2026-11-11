#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	long long ans = 0;
	for (int i = 1, j = n; i < j;) {
		if (b[i] != b[j]) {
			if (a[i] < a[j]) {
				ans += a[i];
				a[j] -= a[i];
				i++;
			} else if (a[i] > b[j]) {
				ans += a[j];
				a[i] -= a[j];
				j--;
			} else {
				ans += a[i];
				i++;
				j--;
			}
		} else {
			i++;
			j--;
		}
	}
	cout << ans;
	return 0;
}