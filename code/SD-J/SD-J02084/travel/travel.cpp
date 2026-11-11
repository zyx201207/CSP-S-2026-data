#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int ci,cii;
	string si,sii;
	cin >> ci >> si >> cii >> sii;
	int a = ((si[0] - '0') * 10 + (si[1] - '0'));
	int b = ((sii[0] - '0') * 10 + (sii[1] - '0'));
	char chi = si[2];
	char chii = sii[2];
	if (ci == cii) {
		cout << 1;
		if (a == b) {
			cout << 1;
			if (chi == 'A' || chi == 'B' || chi == 'C') {
				if (chii == 'B' || chii == 'C' || chii == 'A') {
					cout << 1;
					if (chi == 'B' || chii == 'B') {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << "00";
				}
			} else {
				if (chii == 'D' || chii == 'F') {
					cout << "11";
				} else {
					cout << "00";
				}
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
} 
 
