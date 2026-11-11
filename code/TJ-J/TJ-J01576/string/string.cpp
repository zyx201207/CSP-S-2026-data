#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000000], sum, f;
string s;
char b[1000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 2; i <= n; i++) {
		if (b[i] == b[i - 1]) {
			f = 1;
		} else {
			f = 0;
			break;
		}
	}
	if (f == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += b[i];
		}
	}
	long long l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] != s[r]) {
			sum++;
		}
		l++;
		r--;
	}
	cout << sum;
	return 0;
}