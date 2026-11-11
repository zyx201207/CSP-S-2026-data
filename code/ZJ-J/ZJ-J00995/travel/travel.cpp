#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool f1, f2, f3, f4;
int main () {

	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) f1 = 1;
	if (f1 == 0) {
		cout << "0000";
		return 0;
	}
	string a; a = s1[0] + s1[1];
	string b; b = s2[0] + s2[1];
	if (a == b) f2 = 1;
	if (f2 == 0) {
		cout << "1000";
		return 0;
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') 
	  if (s2[2] != 'D' && s2[2] != 'F') 
	    f3 = 1;
	if (s1[2] == 'D' || s1[2] == 'F') 
	  if (s2[2] != 'A' && s2[2] != 'B' && s2[2] != 'C') 
	    f3 = 1;
	if (f3 == 0) {
		cout << "1100";
		return 0;
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		if (s2[2] != 'D' && s2[2] != 'F' && (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])) f4 = 1;
	}
	if (s1[2] == 'D' || s1[2] == 'F') {
		if (s1[2] == 'D') 
		  if (s2[2] == 'F') f4 = 1;
		if (s1[2] == 'F')
		  if (s2[2] == 'D') f4 = 1;
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}
