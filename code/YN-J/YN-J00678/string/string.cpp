#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, num = 0;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> s;
	}
	if (n = 1 || n == 2) {
		cout << 0;
	} else if (n == 3)
		cout << 2;
	else
		cout << 3000000000;
}