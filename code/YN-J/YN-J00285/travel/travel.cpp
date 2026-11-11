#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int r_c = 0;
	char r_z[3] = {0};

	int x_c = 0;
	char x_z[3] = {0};
	//ÊäÈë
	cin >> r_c;
	for (int i = 0; i < 3; i++)
		cin >> r_z[i];
	cin >> x_c;
	for (int i = 0; i < 3; i++)
		cin >> x_z[i];
	//1
	if (r_c == x_c) {
		cout << 1;
	} else {
		cout << 0;
	}
	//2
	if (r_z[0] == x_z[0] || r_z[1] == x_z[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	cout << 1 << 1;

	return 0;
}