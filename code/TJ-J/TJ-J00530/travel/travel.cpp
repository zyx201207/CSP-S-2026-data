//100
#include <bits/stdc++.h>
using namespace std;

string zc1,zs1,zc2,zs2;

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	cin >> zc1 >> zs1 >> zc2 >> zs2;
	
	if (zc1 != zc2) {
		cout << "0000\n";
		return 0;
	} else {
		cout << "1";
	}
	if (zs1[0] == zs2[0] && zs1[1] == zs2[1]) {
		cout << "1";
	} else {
		cout << "000\n";
		return 0;
	}
	
	char zz1 = zs1[2],zz2 = zs2[2];
	if ( (zz1 <= 'C' && zz2 <= 'C') || (zz1 >= 'D' || zz1 >= 'D') ) {
		cout << "1";
	} else {
		cout << "00\n";
		return 0;
	}
	if ( (zz1 == 'D' && zz2 == 'F') || (zz1 == 'F' && zz2 == 'D') ) {
		cout << "1\n";
	} else {
		if (zz1 == 'A' && zz2 == 'B') {
			cout << "1\n";
		} else if ( (zz1 == 'B' && zz2 == 'A') || (zz1 == 'B' && zz2 == 'C') ) {
			cout << "1\n";
		} else if (zz1 == 'C' && zz2 == 'B') {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
