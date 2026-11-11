#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin >> s1 >> c1 >> s2 >> c2;
	bool tr1 = false;
	bool tr2 = false;
	bool tr3 = false;
	if(c1 == c2) {
		cout << "1";
		tr1 = true;
	} else {
		cout << "0";
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && tr1) {
		cout << "1";
		tr2 = true;
	} else {
		cout << "0";
	}
	char t = '0';
	char t2 = '0';
	if(s1[2] == 'A' || s1[2] == 'B'|| s1[2] == 'C') {
		t = 'L';
	}
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		t2 = 'L';
	}
	if(s1[2] == 'D' || s1[2] == 'F') {
		t = 'R';
	}
	if(s2[2] == 'F' || s2[2] == 'D') {
		t2 = 'R';
	}
	if(t == t2 && tr2 && tr1) {
		cout << "1";
		tr3 = true;
	} else {
		cout << "0";
	}
	if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'E') || (s1[2] == 'E' && s2[2] == 'D') && tr1 && tr2 && tr3) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}
