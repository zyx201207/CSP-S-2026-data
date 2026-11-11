#include <bits/stdc++.h>
using namespace std;
string cq;
string sq;
string ca;
string sa;
string q;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cq >> sq;
	cin >> ca >> sa;
	if (ca == cq) {
		q = "1000";
		for (int a = 0; a < 1; a++) {
			if (sq[a] == sa[a] && sq[a + 1] == sa[a + 1] ) {
				q = "1100";
				for (int z = 2; z < 3; z++) {
					if (sq[z] < 'D' && sa[z] < 'D') {
						q = "1110";
						if (sq[z] + 1 == sa[z]) {
							q = "1111";
						} else if (sq[z] - 1 == sa[z]) {
							q = "1111";
						} else {
							q = "1110";
						}
					} else if (sq[z] >= 'D' && sa[z] >= 'D') {
						q = "1110";
						if (sq[z] + 2 == sa[z]) {
							q = "1111";
						} else if (sq[z] - 2 == sa[z]) {
							q = "1111";
						} else {
							q = "1110";
						}
					} else {
						q = "1100";
					}
				}
			} else {
				q = "1000";
			}
		}
	} else if (ca != cq) {
		q = "0000";
	}
	cout << q;
}