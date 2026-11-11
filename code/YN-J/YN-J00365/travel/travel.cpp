#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string arr[3];

	for (int x = 0; x < 3; x++) {

		cin >> arr[x];//02 01A 02 01B
	}

	if (arr[0] == arr[2]) {
		cout << "1";

		if (arr[1][0] == arr[3][0] and arr[1][1] == arr[3][1]) {
			cout << "1";

			if (arr[1][2] == 'A') {
				if (arr[3][2] == 'B' or arr[3][2] == 'C') {
					cout << "1";

					if (arr[3][2] == 'B') {
						cout << "1";
					} else {
						cout << "0";
					}
				} else {
					cout << "0";
				}
			} else if (arr[1][2] == 'B') {
				if (arr[3][2] == 'A' or arr[3][2] == 'C') {
					cout << "1";
					cout << "1";
				} else {
					cout << "0";
					cout << "0";
				}
			} else if (arr[1][2] == 'C') {
				if (arr[3][2] == 'B' or arr[3][2] == 'A') {
					cout << "1";

					if (arr[3][2] == 'B') {
						cout << "1";
					} else {
						cout << "0";
					}
				} else {
					cout << "0";
				}
			} else if (arr[1][2] == 'D') {
				if (arr[3][2] == 'F') {
					cout << "1";
					cout << "1";
				} else {
					cout << "0";
					cout << "0";
				}
			} else if (arr[1][2] == 'F') {
				if (arr[3][2] == 'D') {
					cout << "1";
					cout << "1";
				} else {
					cout << "0";
					cout << "0";
				}
			} else {
				cout << "0";
			}
		} else {
			cout << "0" << "0" << "0";
		}
	} else {
		cout << "0" << "0" << "0" << "0";
	}

	return 0;
}