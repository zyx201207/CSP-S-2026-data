#include <bits/stdc++.h>
using namespace std;
string s, s1, c, c1;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s >> s1 >> c >> c1;
	
	if (s == c) {
		cout << 1;
		
		if (s1[0] == c1[0] && s1[1] == c1[1]) {
			cout << 1;
			
			if (s1[2] == 'F' || s1[2] == 'D') {
				if (c1[2] == 'F' || c1[2] == 'D') {
					cout << "11";
				} else {
					cout << "00";
				}
			} else {
				if (c1[2] == 'F' || c1[2] == 'D') {
					cout << "00";
				} else {
					cout << 1;
					
					if (abs(s1[2] - c1[2]) == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
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

