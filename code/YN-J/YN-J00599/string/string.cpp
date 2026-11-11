#include <bits/stdc++.h>
using namespace std;
int t[100000];

bool hw(string a) {
	for (int i = a.size(); i >= 1; i--) {
		t[i] = a[i];
	}
	for (int i = 1; i <= a.size(); i++) {
		if (t[i] == a[i]) {
			break;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	freopen(string.in, "r", std.in)
	freopen(string.out, "w", std.out)
	int n, m;
	char c;
	string s, d;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m >> c;
		for (int j = 1; j <= m; j++) {
			s += c;
		}
	}
	if (hw(s)) {
		cout << 0;
	} else {
		cout << 1;
	}
	return 0;
}