#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x, w, xx, ww;
	bool f = 1;
	cin >> x >> w >> xx >> ww;

	for (int i = 1; i <= 2; i++) {

		if (x != xx) {
			cout << "0000";
			f = 0;
			break;
		}

		if (w[0] != ww[0] || w[1] != ww[1]) {
			cout << "1000";
			f = 0;
			break;
		}

		if (w[2] <= 'C' && ww[2] >= 'D' || w[2] >= 'D' && ww[2] <= 'C') {
			cout << "1100";
			f = 0;
			break;
		}
		if (w[2] <= 'C') {
			if (abs(w[2] - ww[2]) > 1) {
				cout << "1110";
				f = 0;
				break;
			}
		}
	}
	if (f == 1) {
		cout << "1111";
	}
	return 0;
}
