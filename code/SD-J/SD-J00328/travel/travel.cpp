#include <bits/stdc++.h>
using namespace std;

string ca,sa,cb,sb;
bool a,b,c,d;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ca >> sa >> cb >> sb;
	if(ca == cb) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if(sa[0] == sb[0] && sa[1] == sb[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if(sa[2] - 'A' < 3 && sb[2] - 'A' < 3) cout << 1;
	else if(sa[2] - 'A' >= 3 && sb[2] - 'A' >= 3) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if(sa[2] - sb[2] == 1 || sa[2] - sb[2] == -1) cout << 1;
	else cout << 0;
	return 0;
} 
