#include <bits/stdc++.h>
using namespace std;

string a;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("trave.out", "w", stdout);
	string b;
	string c;
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
	}


	while (1 < a[2] < 16 && 1 < a[7] < 16) {
		if (a[1] == a[6] && a[2] == a[7]) {
			cout << "1";
			break;
		} else {
			cout << "0";
			break;
		}

		for (int i = 1; i <= 2; i++) {
			if (a[3] == a[8] && a[4] == a[9]) {
				cout << "1";
				break;
			} else {
				cout << "0";
				break;
			}
		}

		if (a[5] + 1 == a[10] || a[5] == a[10] + 1 ) {
			cout << "11";
		} else {
			cout << "00";

		}


	}


}