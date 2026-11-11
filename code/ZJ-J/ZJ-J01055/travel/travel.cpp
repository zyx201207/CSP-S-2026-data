#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	int ac=(a1[0]-'0')*10+a1[1]-'0';
	int ap=(a2[0]-'0')*10+a2[1]-'0';
	char as=a2[a2.size()-1];
	int bc=(b1[0]-'0')*10+b1[1]-'0';
	int bp=(b2[0]-'0')*10+b2[1]-'0';
	char bs=b2[b2.size()-1];
	if (ac==bc) {
		if (ap==bp) {
			if ((as<='C'&&bs<='C')||(as>='D'&&bs>='D')) {
				if (abs(as-bs)==1&&!(as=='C'&&bs=='D')&&!(as=='D'&&bs=='C')) {
					cout << "1111";
				} else {
					cout << "1110";
				}
			} else {
				cout << "1100";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
