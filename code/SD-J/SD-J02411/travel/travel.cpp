#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int a, b, c, d;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) {
		cout << 1;
		int flag = 1;
		for(int i = 0; i < 2; i++) {
			if(s2[i] != s4[i]) flag = 0;
		}
		if(!flag) {
			cout << "000";
		} else {
			cout << 1;
			if(s2[2] >= 'A' && s2[2] <= 'C' && s4[2] >= 'A' && s4[2] <= 'C') {
				cout << 1;
				if(abs(int(s2[2]) - int(s4[2])) == 1) cout<<1;
				else cout << 0;
			} else {
				if(s2[2] == 'D' || s2[2] == 'F') {
					if(s4[2] == 'D' || s4[2] =='F') {
						cout << 1;
						cout << 1;
					}
					else {
						cout << 0;
					} 
				}
				else cout <<"00";
			}
		}

	} else cout << "0000";

	return 0;
}
