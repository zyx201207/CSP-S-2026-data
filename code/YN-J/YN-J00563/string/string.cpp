#include <bits/stdc++.h>
using namespace std;

struct str {
	int sl;
	char zm;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	str a[10000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].sl >> a[i].zm;
	}
	string b, c;
	for (int i = 0; i < n; i++) {
		b = b  a[i].sl * a[i].zm;
	}
	for (int i = n - 1; i >= 0; i--) {
		c = c  a[i].sl * a[i].zm;
	}
	if (b == c) {
		cout << 0;
	}
	return 0;
}