#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	char a[20000];
	char c[20000];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 0; i < n; i++) {
		if (c[i] = c[i + 1]) {
			cout << "0";
		}
	}
	return 0;
}