#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	cout << 0;
	return 0;
}