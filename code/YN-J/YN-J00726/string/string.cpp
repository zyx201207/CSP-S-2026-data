#include <bits/stdc++.h>
using namespace std;
int n, a[2000005];
char c[2000005];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int sum = 0;
	int l = 1;
	int r = n, f = 1;
	for (int i = 1; i < r; i++) {
		if (c[l] != c[r] ) {
			f = 0;
			break;
		} else if ( a[l] != a[r] && i + 1 != r) {
			f = 0;
			break;
		}
		r--;
	}
	if (f == 1) {
		cout << 0;
		return 0;
	}
	r = n;
	while (l < r) {
		if (c[l] != c[r] ) {
			sum += max(a[l], a[r]);
		} else if ( a[l] != a[r]) {
			sum += max(a[l], a[r]) - min(a[l], a[r]);
		}
		l++;
		r--;
	}
	cout << sum;
}