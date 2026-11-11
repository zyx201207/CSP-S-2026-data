#include <bits/stdc++.h>
using namespace std;

bool check(char a, char b) {
	char left[5] = {'A', 'B', 'C'};
	char right[5] = {'D', 'F'};
	bool a1, b1;
	for (int i = 0; i <= 2; i++) {
		if (a == left[i]) {
			a1 = 1;
		}
		if (b == left[i]) {
			b1 = 1;
		}
	}
	for (int i = 0; i <= 1; i++) {
		if (a == right[i]) {
			a1 = 0;
		}
		if (b == right[i]) {
			b1 = 0;
		}
	}
	if (a1 != b1) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int car1, car2;
	char seat1[5], temp, seat2[5], temp2;

	cin >> car1 >> seat1[1] >> seat1[2] >> seat1[3] >> temp >> car2 >> seat2[1] >> seat2[2] >> seat2[3];
	if (car1 != car2) {
		cout << "0000";
		return 0;
	} else {
		if (seat1[2] != seat2[2] || seat1[1] != seat2[1]) {
			cout << "1000";
			return 0;
		} else {
			if (check(seat1[3], seat2[3])) {
				cout << "1100";
				return 0;
			} else {
				if (!((seat2[3] == seat1[3] + 1 || seat2[3] == seat1[3] - 1) && !((seat2[3] == 'C' && seat1[3] == 'D') || (seat2[3] == 'D' && seat1[3] == 'C')))) {
					cout << "1110";
					return 0;
				} else {
					cout << "1111";
					return 0;
				}
			}
		}
	}



	return 0;
}