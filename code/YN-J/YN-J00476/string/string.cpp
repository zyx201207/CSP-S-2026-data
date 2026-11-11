#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long a[N];
char c[N];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long L = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		L += a[i];
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		if (c[l] != c[r]) {
			ans += min(a[l], a[r]);
//			cout << l << " " << r << ":" << min(a[l], a[r]) << "\n";
		}
		if (a[l] > a[r]) {
			a[l] -= a[r];
			a[r] = 0;
			r--;
		} else if (a[l] < a[r]) {
			a[r] -= a[l];
			a[l] = 0;
			l++;
		} else if (a[l] == a[r]) {
			a[l] = 0;
			a[r] = 0;
			l++;
			r--;
		}
	}
	cout << ans;
}