#include <bits/stdc++.h>
using namespace std;
bool t[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int pd = 0;
	string a, b, a1, b1;
	cin >> a >> a1 >> b >> b1;
	if (a == b)
		t[1] = 1;
	if (a1[0] == b1[0] && a1[1] == b1[1] && t[1] == 1)
		t[2] = 1;
	if (a1[2] >= 'A' && b1[2] >= 'A' && a1[2] <= 'C' && b1[2] <= 'C' && t[2] == 1) {
		t[3] = 1;
		pd = 1;
	} else {
		if (a1[2] >= 'D' && a1[2] <= 'F' && b1[2] <= 'D' && b1[2] <= 'F' && t[2] == 1) {
			t[3] = 1;
			pd = 2;
		}
	}
	if (pd == 1) {
		if (abs(int(a1[2]) - int(b1[2])) == 1)
			t[4] = 1;
	}
	if (pd == 2)
		t[4] = 1;
	for (int i = 1; i <= 4; i++) {
		cout << t[i];
	}
	return 0;
}
