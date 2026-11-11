#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	char n1, n2, n3, m1, m2, m3;
	cin >> n >> n1 >> n2 >> n3 >> m >> m1 >> m2 >> m3;
	int nn = (n1 - '0') * 10 + (n2 - '0');
	int mm = (m1 - '0') * 10 + (m2 - '0');

	if (n != m) {
		cout << "0000";
		return 0;
	}

	cout << "1";

	if (nn != mm) {
		cout << "000";
		return 0;
	}

	cout << "1";

	if (!(('A' <= n3 && n3 <= 'C' && 'A' <= m3 && m3 <= 'C') || ('D' <= n3 && n3 <= 'F' && 'D' <= m3 && m3 <= 'F'))) {
		cout << "00";
		return 0;
	}

	cout << "1";

	if (n3 - 1 == m3 || m3 - 1 == n3) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}