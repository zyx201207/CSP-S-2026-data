#include <bits/stdc++.h>
using namespace std;
long long n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n == 1) {
		long long c1;
		string s;
		cin >> c1 >> s;
		cout << "0";
		return 0;
	} else if (n == 2) {
		for (int i = 1; i <= n; i++) {
			long long c1;
			string s;
			cin >> c1 >> s;
			if (c1[1] > c1[0]) {
				cout << c1[0];
			}
		}
	}

	return 0;
}