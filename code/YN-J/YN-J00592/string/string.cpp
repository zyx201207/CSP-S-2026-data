#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long l;
	string m;
	string s;

	for (int i = 0; i < n; ++i) {

		cin >> l;
		cin >> m;

		for (int i = 0; i < l; ++i) {

			s += m;
		}
	}

	if (s.begin() == s.end()) {
		cout << "0";
	}

	return 0;
}