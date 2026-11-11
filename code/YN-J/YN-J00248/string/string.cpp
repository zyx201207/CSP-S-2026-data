#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n;

struct str {
	long long x;
	char c;
};
str a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	if (n == 1) {
		cout << 0 << "\n";
	} else if (n == 2) {
		if (a[1].c == a[2].c) {
			cout << 0;
		} else if (a[1].x == a[2].x) {
			cout << a[1].x;
		} else if (abs(a[1].x - a[2].x) == 1) {
			cout << min(a[1].x, a[2].x);
		} else if (a[1].x == 1 || a[2].x == 1) {
			cout << 1;
		} else {
			cout << min(a[1].x, a[2].x);
		}
	} else {
		cout << 0;
	}
	return 0;
}