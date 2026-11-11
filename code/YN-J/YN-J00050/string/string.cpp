#include <bits/stdc++.h>
using namespace std;

int main() {
	char l, a[10000];
	int n, x, p = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> l;
		for (int j = p; j <= p + x; j++) {
			a[j] = l;
		}
		p += x;
	}
	cout << p << endl;

	return 0;
}