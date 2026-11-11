#include <bits/stdc++.h>
using namespace std;

int c1,a1;
char c2[3],a2[3];
int main() {
	
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	
	cin >> c1 >> c2 >> a1 >> a2;
	if(c1 == a1) {
		cout << '1';
		if(c2[0] == a2[0] && c2[1] == a2[1]) {
			cout << '1';
			if(c2[2] >= 'D' && a2[2] >= 'D' || c2[2] < 'D' && a2[2] < 'D') {
				cout << '1';
				if(c2[2] - a2[2] == 1 || a2[2] - c2[2] == 1) {
					cout << '1';
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}