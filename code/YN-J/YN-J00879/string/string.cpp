#include <bits/stdc++.h>
using namespace std;
string s[1000005];

int main() {
	freopen("string.in", "r", "stdin");
	freopen("string.out", "w", "stdout");
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int ai, ci;
		cin >> ai >> ci;
		if (n <= 1) {
			cout << "0";
			return 0;
		}
		if (ci == ci) {
			cout << "0";
			return 0;
		} else {
			cout << ai;
		}
	}
	return 0;
}