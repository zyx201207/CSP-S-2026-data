#include <bits/stdc++.h>
using namespace std;
map <char,int> mp;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	mp['A']++;
	mp['B']++;
	mp['C']++;
	string ss1,ss2;
	ss1=s1.substr(0,2);
	ss2=s2.substr(0,2);
	if(c1==c2) {
		cout << 1;
		if(ss1==ss2) {
			cout << 1;
			if(mp[s1[2]]==mp[s2[2]]) {
				cout << 1;
				if(s1[2]=='D'&&s2[2]=='F') {
					cout << 1;
				} else {
					if(s1[2]=='A'&&s2[2]=='B') {
						cout << 1;
					} else {
						if(s1[2]=='B'&&s2[2]=='C') {
							cout << 1;
						} else {
							cout << 0;
						}
					}
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
		return 0;
	}
	return 0;
}
