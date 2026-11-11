#include<bits/stdc++.h>
using namespace std;
//#define int long long

string cs1, ws1;
string cs2, ws2;

bool check(char x, char y){
	if ((x == 'A' && y == 'B') || (x == 'B' && y == 'A'))
		return true;
	if ((x == 'B' && y == 'C') || (x == 'C' && y == 'B'))
		return true;
	if ((x == 'A' && y == 'C') || (x == 'C' && y == 'A'))
		return true;
	if ((x == 'D' && y == 'F') || (x == 'F' && y == 'D'))
		return true;
	return false;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> cs1 >> ws1 >> cs2 >> ws2;
	if (cs1 == cs2) {
		cout << 1;
		if (ws1[0] == ws2[0] && ws1[1] == ws2[1]) {
			cout << 1;
			if (check(ws1[2], ws2[2])) {
				cout << 1;
				if (int(ws1[2]) == int(ws2[2]) + 1 || int(ws1[2]) == int(ws2[2]) - 1) {
					cout << 1;
				} 
				else 
					cout << 0;
			}
			else 
				cout << "00";
		}
		else 
			cout << "000";
	}
	else 
		cout << "0000";
	return 0;
}
