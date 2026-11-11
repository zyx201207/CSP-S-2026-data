#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int n, m;
	string n1, m1;
	cin >> n >> n1 >> m >> m1;
	int a1 = n1[0] - '0';
	int a2 = n1[1] - '0';
	int b1 = m1[0] - '0';
	int b2 = m1[1] - '0';
	char a3 = n1[2];
	char b3 = m1[2];
	int a4 = a1 * 10 + a2;
	int b4 = b1 * 10 + b2;
	int x = 0, y = 0, z = 0;
	//1
	if (n == m) {
		cout << "1";
		x = 1;
	} else {
		cout << "0";
		x = 0;
	}
	//2
	if (x == 1 and a4 == b4) {
		cout << "1";
		y = 1;
	} else {
		cout << "0";
		y = 0;
	}
	// 3
	if (x == 1 and y == 1) {
		if (a3 == 'A' and b3 == 'B' or a3 == 'B' and b3 == 'A' or a3 == 'A' and b3 == 'C' or a3 == 'C' and b3 == 'A'
		        or a3 == 'C' and b3 == 'B' or a3 == 'B' and b3 == 'C' or a3 == 'D' and b3 == 'F' or a3 == 'F' and b3 == 'D') {
			cout << "1";
			z = 1;
		} else {
			cout << "0";
			z = 0;
		}
	} else {
		cout << "0";
		z = 0;
	}
	//4
	if (x == 1 and y == 1 and z == 1) {
		if (a3 == 'A' and b3 == 'B' or a3 == 'B' and b3 == 'A' or a3 == 'C' and b3 == 'B' or a3 == 'B' and b3 == 'C'
		        or a3 == 'D' and b3 == 'F' or a3 == 'F' and b3 == 'D') {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}