#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cR;
string sR;
int cX;
string sX;
int mp[1003];
char ch1, ch2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cR >> sR >> cX >> sX;
	mp[0] = mp[1] = mp[2] = 1;
	mp[3] = mp[5] = 2;
	if(cR == cX) {
		cout << "1";
		if(sR[0] + sR[1] == sX[0] + sX[1]) {
			cout << "1";
			if(mp[sR[2] - 'A'] == mp[sX[2] - 'A']) {
				cout << "1";
				ch1 = sR[2], ch2 = sX[2];
				if(ch1 > ch2) swap(ch1, ch2);
				if(ch1 == 'A' && ch2 == 'B' || ch1 == 'B' && ch2 == 'C' || ch1 == 'D' && ch2 == 'F') {
					cout << "1";
				} else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
} 
