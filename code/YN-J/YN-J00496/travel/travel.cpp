//¿ª×¢ÊÍ£¡£¡£¡
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string sc1;
	string sc2;
	string ss1;
	string ss2;
	cin >> sc1 >> ss1 >> sc2 >> ss2;
	if (sc1 == sc2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (ss1[0] == ss2[0] && ss1[1] == ss2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((ss1[2] == 'A' || ss1[2] == 'B' || ss1[2] == 'C') && (ss2[2] == 'A' || ss2[2] == 'B' || ss2[2] == 'C')) {
		cout << "1";
	} else if ((ss1[2] == 'D' || ss1[2] == 'F') && (ss2[2] == 'D' || ss2[2] == 'F')) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if ((ss1[2] == 'A' || ss1[2] == 'B') && (ss2[2] == 'A' || ss2[2] == 'B')) {
		cout << "1";
		return 0;
	} else if ((ss1[2] == 'B' || ss1[2] == 'C') && (ss2[2] == 'B' || ss2[2] == 'C')) {
		cout << "1";
		return 0;
	}  else if ((ss1[2] == 'D' || ss1[2] == 'F') && (ss2[2] == 'D' || ss2[2] == 'F')) {
		cout << "1";
		return 0;
	} else {
		cout << "0";
		return 0;
	}
	return 0;
}