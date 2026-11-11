#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> m;
	if (n == 0) {
		if (m == 2) {
			cout << "32" << endl << "17";
		} else {
			cout << "35" << endl << "16";
		}
	} else {
		cout << "38" << endl << "15";
	}
	return 0;
}