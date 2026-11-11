#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool f1, f2, f3, f4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string p1, p2;
	p1 = s1[0];
	p2 = s2[0];
	p1 += s1[1];
	p2 += s2[1];
	char d1 = s1[2], d2 = s2[2];
	int x1, x2;
	if(d1 == 'A' || d1 == 'B' || d1 == 'C') x1 = 1;
	else x1 = 2;
	if(d2 == 'A' || d2 == 'B' || d2 == 'C') x2 = 1;
	else x2 = 2;
	if(c1 == c2) {
		f1 = 1;
		if(p1 == p2) {
			f2 = 1;
			if(x1 == x2) {
				f3 = 1;
				if(d1 + 1 == d2 || d2 + 1 == d1) f4 = 1;
			}
		}
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
