#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int sta1, sta2, sta3, sta4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		sta1 = 1;
		string tmp1, tmp2;
		tmp1 = s1[0] + s1[1];
		tmp2 = s2[0] + s2[1];
		if (tmp1 == tmp2) {
			sta2 = 1;
			char P1, P2;
			P1 = s1[2];
			P2 = s2[2];
			if (P1 <= 'C' && P1 >= 'A' && P2 <= 'C' && P2 >= 'A' || P1 == 'D' && P2 == 'F' || P2 == 'D' && P1 == 'F') {
				sta3 = 1;
				char p = P1 + 1;
				char d = P1 - 1;
				if (p == 'E') {
					p = 'D';
				} 
				if (d == 'E') {
					d = 'F';
				}
				if (p == P2 || d == P2) {
					sta4 = 1;
				}
			}
		}
	}
	cout << sta1 << sta2 << sta3 << sta4;
	return 0;
}