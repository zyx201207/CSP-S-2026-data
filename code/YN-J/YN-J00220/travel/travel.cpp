#include <bits/stdc++.h>
using namespace std;

struct node {
	string car, seat;
	bool gud;
} a[7];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		cin >> a[i].car >> a[i].seat;
		if (a[i].seat[2] >= 'A' && 'C' >= a[i].seat[2]) {
			a[i].gud = 1;
		} else
			a[i].gud = 0;

	}

	if (a[1].car == a[2].car) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}



	for (int i = 0; i < 2; i++) {
		if (a[1].seat[i] != a[2].seat[i]) {
			cout << "000";
			return 0;
		}
	}

	cout << "1";




	if (a[1].gud != a[2].gud) {
		cout << "0";

	} else
		cout << "1";



	if (abs(a[1].seat[2] - a[2].seat[2]) == 1)
		if (a[1].gud == a[2].gud)
			cout << "1";
		else
			cout << "0";
	else
		cout << "0";



	return 0;
}