#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	char s[1000000] = {0}, b[999999] = {0};
	int n, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char v;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> v;
			s[i] = v;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		b[i] = s[i];
	}
	for (int i = 0; i < n; i--) {
		if (b[i] != s[i]) {
			num++;
		}
	}
	num = num / 2;
	cout << num;
	return 0;
}