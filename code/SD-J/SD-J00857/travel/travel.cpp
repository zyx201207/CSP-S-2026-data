#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string a1, b1, a2, b2;
	bool x1, x2, x3, x4;
	cin >> a1 >> b1 >> a2 >> b2;
	x1 = (a1 == a2);
	int c1 = (b1[0] - 48) * 10 + b1[1] - 48, c2 = (b2[0] - 48) * 10 + b2[1] - 48;
	x2 = (x1 && c1 == c2);
	bool d1, d2;
	if (b1[2] == 'D' && b1[2] == 'F') d1 = 1;
	else d1 = 0;
	if (b2[2] == 'D' || b2[2] == 'F') d2 = 1;
	else d2 = 0;
	x3 = (x2 && d1 == d2);
	if ((b1[2] == 'D' && b2[2] == 'F') || (b1[2] == 'F' && b2[2] == 'D') ||
	(b1[2] == 'A' && b2[2] == 'B') || (b1[2] == 'B' && (b2[2] == 'C' || b2[2] == 'A'))||
	(b1[2] == 'C' && b2[2] == 'B')) {
		x4 = x3;
	}
	else x4 = 0;
	cout << x1 << x2 << x3 << x4 << endl;
	return 0;
}
