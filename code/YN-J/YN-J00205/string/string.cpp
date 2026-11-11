#include <bits/stdc++.h>
using namespace std;

bool hui(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	if (a == b) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, f = -1;
	string a = "";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		if (f == -1)
			f = b;
		char c;
		cin >> c;
		for (int i = 0; i < b; i++) {
			a += c;
		}
	}
	if (hui(a)) {
		cout << "0" << endl;
		return 0;
	} else if (f >= a.size() - 1 - f) {
		cout << a.size() - 1 - f << endl;
		return 0;
	} else {
		if ((a.size() - 1) % 2 == 1 && ((a.size() - 1) / 2 != (a.size() - 1) / 2 + 2)) {
			cout << a.size() - 1 - (a.size() / 2 + 1) << endl;
			return 0;
		} else if ((a.size() - 1) % 2 == 0 && ((a.size() - 1) / 2 != (a.size() - 1) / 2 + 1)) {
			cout << a.size() - 1 - (a.size() - 1) / 2 + 1 << endl;
			return 0;
		} else {
			cout << a.size() / 2 << endl;
			return 0;
		}
	}

	return 0;
}