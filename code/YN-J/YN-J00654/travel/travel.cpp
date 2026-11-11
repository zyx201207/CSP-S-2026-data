#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string n1, n2;
	string m1, m2;
	cin >> n1 >> n2 >> m1 >> m2;
	if (n1[0] == m1[0] && n1[1] == m1[1]) {
		cout << 1;
		if (n2[0] == n2[0] && n2[1] == m2[1]) {
			cout << 1;
			if (n2[2] < 'D' && m2[2] < 'D' || n2[2] > 'C' && m2[2] > 'c') {
				cout << 1;
				if (n2[2] == m2[2] - 1 || n2[2] - 1 == m2[2]) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}