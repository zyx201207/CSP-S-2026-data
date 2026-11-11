#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	// 1
	if ( c1 != c2 ) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	
	// 2
	if ( s1.substr(0, 2) != s2.substr(0, 2) ) {
		cout << "000";
		return 0;
	}
	cout << 1;
	
	// 3
	if ( ! ( ( s1[2] <= 'C' && s2[2] <= 'C' ) || ( s1[2] >= 'D' && s2[2] >= 'D' ) ) ) {
		cout << "00";
		return 0;
	}
	cout << 1;
	
	// 4
	if ( s1[2] == 'D' ) s1[2]++;
	if ( s2[2] == 'D' ) s2[2]++;
	
	if ( abs(s1[2] - s2[2]) == 1 ) cout << 1;
	else cout << 0;
	
	
	return 0; 
}
