#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s1,s2,s3,s4;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		cout << "1";
		if (s2.substr(0,2) == s4.substr(0,2)) {
			cout << "1";
			if ((s2[2] == 'A' || s2[2] == 'B' || 
					s2[2] == 'C') && (s4[2] == 'A' || 
					s4[2] == 'B' || s4[2] == 'C') || 
					(s2[2] == 'D' || s2[2] == 'E') && 
					(s4[2] == 'D' || s4[2] == 'E')) {
				cout << "1";
				if (abs((int)s2[2] - (int)s4[2]) == 1)
					cout << "1";
				else
					cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
