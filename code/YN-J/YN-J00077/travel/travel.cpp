#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ll c1, c2;
	char s1, s2;
	ll p1, p2;
	cin >> c1 >> p1 >> s1 >> c2 >> p2 >> s2;

	//

	if (c1 == c2)
		cout << "1";
	else {
		cout << "0000";
		return 0;
	}

	//

	if (p1 == p2)
		cout << "1";
	else {
		cout << "000";
		return 0;
	}

	//
	if (s1 == 'A' || s1 == 'B' || s1 == 'C') {
		if (s2 == 'A' || s2 == 'B' || s2 == 'C') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	}

	if (s1 == 'D' || s1 == 'F') {
		if (s2 == 'D' || s2 == 'F') {
			cout << "1";
		} else {
			cout  << "00";
			return 0;
		}
	}


	//
	if (s1 == 'A' || s1 == 'B' || s1 == 'C') {
		if (s1 == 'A' && s2 == 'B') {
			cout << "1";
			return 0;
		} else {
			cout << "0";
			return 0;
		}

		if (s1 == 'B' && s2 == 'C' || s2 == 'A') {
			cout << "1";
			return 0;
		} else {
			cout << "0";
			return 0;
		}

		if (s1 == 'C' && s2 == 'B') {
			cout << "1";
			return 0;
		} else {
			cout << "0";
			return 0;
		}

		cout << "ERROR";
		return 0;

	}

	if (s1 == 'D' || s1 == 'F') {
		if (s1 == 'D' && s2 == 'F') {
			cout << "1";
			return 0;
		} else {
			cout  << "0";
			return 0;
		}

		if (s1 == 'F' && s2 == 'D') {
			cout << "1";
			return 0;
		} else {
			cout  << "0";
			return 0;
		}

		cout << "ERROR";
		return 0;
	}

	return 0;
}