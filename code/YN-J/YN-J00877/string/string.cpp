#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int a;
	string c, s;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s = s + c;
		}
	}
	if (n == 1) {
		cout << 0;
	}
	if (s.size() == 2) {
		if (s[0] == s[1]) {
			cout << 0;
		} else {
			cout << 1;
		}
	}
	string t, t1;
	t = s;
	int sum = 0;
	for (int i = s.size(); i >= 0; i--) {
		t1 = t1 + s[i];
	}
	if (t == t1 && s.size() > 2) {
		cout << 0;
	} else {
		string x = s.substr(0, s.size() / 2);
		string y = s.substr(s.size() / 2, s.size() / 2);
		for (int i = 0; i < x.size(); i++) {
			if (x[i] != y[i]) {
				sum++;
			}
		}
		cout << sum;
	}
	return 0;
}