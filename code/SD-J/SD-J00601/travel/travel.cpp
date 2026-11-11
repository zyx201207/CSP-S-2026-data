#include <bits/stdc++.h>
using namespace std;

int a, c, b, d;
string s, t;
bool fr,fx;///30min

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> s >> c >> t;
	b = (s[0]-'0')*10+s[1]-'0';
	d = (t[0]-'0')*10+t[1]-'0';
	if(s[2]-'A' < 3) fr = 1;
	if(t[2]-'A' < 3) fx = 1;
	if(a == c) {
		cout << "1";
		if(b == d) {
			cout << "1";
			if(fr == fx) {
				cout << "1";
				if(!fr or (abs(s[2]-t[2])==1)) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}

