#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
		string r = "" + s1[0] + s1[1];
		string x = "" + s2[0] + s2[1];
		if(r == x) {;
			cout << "1";
			char rr = s1[2];
			char xr = s2[2];
			if((rr <= 'C' && xr <= 'C') || (rr >= 'D' && xr >= 'D')) {
				cout << "1";
				if(abs(int(xr - rr)) == 1) {
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
			else {
				cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
