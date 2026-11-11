#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, c, n[3], m[3];
	string b, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		for (int i = 0; i < b.length(); i++) {
			cin >> n[i];
		}
		for (int j = 0; j < d.length(); j++) {
			cin >> m[j];
		}
		if (m[0] == n[0] && m[1] == n[1]) {
			if (m[2] + 1 == n[2] || m[2] - 1 == n[2]) {
				cout << "1111";
			} else if (n[2] + 1 == m[2] || n[2] - 1 == m[2]) {
				cout << "1111";
			}
		} else {
			cout << "1000";
		}

	} else {
		cout << "0000";
	}
	return 0;
}