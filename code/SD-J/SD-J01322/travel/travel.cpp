#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
string s,t;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >> t;
	if(a==b) {
		cout << 1;
		if(s[0]==t[0]&&s[1]==t[1]) {
			cout << 1;
			long long tt=0;
			if(s[2]=='A') {
				if(t[2]=='B'||t[2]=='C') {
					tt=1;
				}
			}
			if(s[2]=='B') {
				if(t[2]=='A'||t[2]=='C') {
					tt=1;
				}
			}
			if(s[2]=='C') {
				if(t[2]=='A'||t[2]=='B') {
					tt=1;
				}
			}
			if(s[2]=='D') {
				if(t[2]=='F') {
					tt=1;
				}
			}
			if(s[2]=='F') {
				if(t[2]=='D') {
					tt=1;
				}
			}
			if(tt==1) {
				cout << 1;
				if((s[2]=='A'&&t[2]=='C')||(s[2]=='C'&&t[2]=='A')) {
					cout << 0;
				} else {
					cout << 1;
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
