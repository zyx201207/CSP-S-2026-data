#include <bits/stdc++.h>

using namespace std;

bool check(char c1, char c2) {
	if (c1 < c2) swap(c1, c2);
	if (c1 == 'F' && c2 == 'D') return true;
	if (c1 == 'D') return false;
	if (char(c1 - 1) == c2) return true;
	return false;
}

int main( ) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) cout << '1';
	else cout << 0;
	if (s1 == s3 
		&& s2[0] == s4[0] && s2[1] == s4[1]) cout << 1;
	else cout << 0;
	if (s1 == s3 
		&& s2[0] == s4[0] && s2[1] == s4[1] 
		&& (s2[2] <= 'C' && s4[2] <= 'C' || s2[2] >= 'D' && s4[2] >= 'D')) cout << 1;
	else cout << 0;
	if (s1 == s3 
		&& s2[0] == s4[0] && s2[1] == s4[1] 
		&& (s2[2] <= 'C' && s4[2] <= 'C' || s2[2] >= 'D' && s4[2] >= 'D')
		&& check(s2[2], s4[2])) cout << 1;
	else cout << 0;
	return 0;
}
