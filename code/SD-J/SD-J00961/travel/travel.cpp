#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int p1, p2, w1, w2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) { 
	 	cout << "1";
		p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		w1 = (s1[2] == 'D' ? 5 : s1[2] - 'A' + 1);
		w2 = (s2[2] == 'D' ? 5 : s2[2] - 'A' + 1);
//		cout << p1 << " " << w1 << "   " << p2 << " " << w2;
		if(p1 != p2) {
			cout << "000";
		}
		else {
			cout << "1";
			if((w1 <= 3 && w2 <= 3) || (w1 >= 5 && w2 >= 5)) {
				cout << "1";
				if(abs(w1 - w2) == 1) cout << "1";
				else cout << "0";
			}
			else {
				cout << "00";
			}
		}
	}
	else {
		cout << "0000";
	}
	return 0;
} 
