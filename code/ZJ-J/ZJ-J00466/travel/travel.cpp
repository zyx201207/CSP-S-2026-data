#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(char z1, char z2) {
	if('A' <= z1 && z1 <= 'C' && 'A' <= z2 && z2 <= 'C') {
		return true;
	}
	if('D' <= z1 && z1 <= 'F' && 'D' <= z2 && z2 <= 'F') {
		return true;
	}
	return false;
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	string w1;
	w1.push_back(s1[0]);
	w1.push_back(s1[1]);
	string w2;
	w2.push_back(s2[0]);
	w2.push_back(s2[1]);
	if(w1 == w2) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	char z1 = s1[2], z2 = s2[2];
	if(check(z1, z2)) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if(abs(z1 - z2) == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}