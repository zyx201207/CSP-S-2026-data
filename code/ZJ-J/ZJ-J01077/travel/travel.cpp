#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) {
		cout << 1;
		string t1 = s2.substr(0, 2);
		string t2 = s4.substr(0, 2);
		//cout << t1 << " " << t2 << endl;
		if(t1 == t2) {
			cout << 1;
			char a = s2[2], b = s4[2];
			if((a >= 'D' && b >= 'D') || (a <= 'C' && b <= 'C')) {
				cout << 1;
				if((abs(a - b) == 1) || (a >= 'D')) cout << 1;
				else cout << 0;
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
