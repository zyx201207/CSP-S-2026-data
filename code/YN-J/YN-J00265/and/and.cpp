#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (n / m == 0) {
			n++;
		}
	}
	cout << n;
	return 0;
}