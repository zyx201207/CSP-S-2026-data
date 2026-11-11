#include <bits/stdc++.h>
using namespace std;
bool t[10], p;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, a1, b, b1, ans;
	cin >> a >> a1 >> b >> b1;
	if (a == b)
		t[1] = 1;
	if (a1[1] == b1[1] && t[1] == 1)
		t[2] = 1;
	if ((a1[2] == 'A' && b1[2] == 'B' && t[2] == 1) || (a1[2] == 'B' && b1[2] == 'A' && t[2] == 1) || (a1[2] == 'B'
	        && b1[2] == 'C' && t[2] == 1) || (a1[2] == 'C' && b1[2] == 'B' && t[2] == 1) || (a1[2] == 'C' && b1[2] == 'A'
	                && t[2] == 1) || (a1[2] == 'A' && b1[2] == 'C' && t[2] == 1) ) {
		t[3] = 1;
		p = 1;
	} else if ((a1[2] == 'D' && b1[2] == 'F' && t[2] == 1) || (a1[2] == 'F' && b1[2] == 'D' && t[2] == 1)) {
		t[3] = 1;
	}
	if (p == 1) {
		if (abs(int (a1[2]) - int (b1[2])) == 1) {
			t[4] = 1;
		}
	} else if (p == 0) {
		t[4] == 1;
	}
	for (int i = 1; i <= 4; i++) {
		cout << t[i];
	}
	return 0;
}