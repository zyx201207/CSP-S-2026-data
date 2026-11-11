#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;

struct node {
	int x, y, z;
} a[10];

void ks() {
	int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
	for (int i = 0; i <= 1; i++) {
		a1 = a1 * 10 + (c1[i] - '0');
		a2 = a2 * 10 + (s1[i] - '0');
		b1 = b1 * 10 + (c2[i] - '0');
		b2 = b2 * 10 + (s2[i] - '0');
	}
	a3 = s1[2] - 'A' + 1;
	b3 = s2[2] - 'A' + 1;
	a[1].x = a1;
	a[1].y = a2;
	a[1].z = a3;
	a[2].x = b1;
	a[2].y = b2;
	a[2].z = b3;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	ks();
	int cnt = 0;
	if (a[1].x == a[2].x) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if (a[1].y == a[2].y) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((a[1].z <= 3 && a[2].z <= 3) || (a[1].z >= 4 && a[2].z >= 4)) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (abs(a[1].z - a[2].z) == 1) {
		cout << 1;
	} else
		cout << 0;
//	cout << "      " << a[1].z << ' ' << a[2].z;
	return 0;
}
