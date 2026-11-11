#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	string k1 = s1.substr(0, 2);
	string k2 = s2.substr(0, 2);
	if(k1 == k2) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	char k3 = s1[2];
	char k4 = s2[2];
	if(k3 == 'A' || k3 == 'B' || k3 == 'C') {
		if(k4 == 'A' || k4 == 'B' || k4 == 'C') {
			cout << "1";
		} else if(k4 == 'D' || k4 == 'F') {
			cout << "00";
			return 0;
		}
	}
	if(k3 == 'D' || k3 == 'F') {
		if(k4 == 'D' || k4 == 'F') {
			cout << "1";
		} else if(k4 == 'A' || k4 == 'B' || k4 == 'C') {
			cout << "00";
			return 0;
		}
	}
	int p1 = k3 - '0';
	int p2 = k4 - '0';
	if(abs(p1 - p2) == 1) {
		cout << "1";
	} else {
		cout << "0";
		return 0;
	}
	return 0;
}
