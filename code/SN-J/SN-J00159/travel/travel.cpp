#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, answer;
bool cmp (char a, char b) {
	if (a == 'A' && b == 'C') {
		return true;
	}
	if (a == 'C' && b == 'A') {
		return true;
	}
	if (a == 'A' && b == 'B') {
		return true;
	}
	if (b == 'B' && a == 'C' ) {
		return true;
	}
	if (a == 'B' && b == 'C' ) {
		return true;
	}
	if (a == 'B' && b == 'A') {
		return true;
	}
	if ((a == 'D' && b == 'F') || (a == 'F' && b == 'D')) {
		return true;
	}
	return false;
}
bool cmp2 (char a, char b) {
	if ((a == 'A' && b == 'B') || (b == 'A' && a == 'B')) {
		return true;
	}
	if ((a == 'B' && b == 'C') || (b == 'B' && a == 'C')) {
		return true;
	}
	if ((a == 'D' && b == 'F') || (b == 'D' && a == 'F')) {
		return true;
	}
	return false;
}
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		answer += "1";
	}
	else {
		answer += "0";
	}
	
	if (c1 == c2 && s1[1] == s2[1]) {
		answer += "1";
	}
	else {
		answer += "0";
	}
	
	if (c1 == c2 && s1[1] == s2[1] && cmp(s1[2], s2[2])) {
		answer += "1";
	}
	else {
		answer += "0";
	}
	
	if (c1 == c2 && s1[1] == s2[1] && cmp(s1[2], s2[2]) && cmp2(s1[2], s2[2])) {
		answer += "1";
	}
	else {
		answer += "0";
	}
	cout << answer << '\n'; 
	return 0;
} 
