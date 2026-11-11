#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, s1, s2, s3;
	cin >> s >> s1 >> s2 >> s3;
	if (s == s2) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	int cnt = 0;
	string s4, s5;
	s4 = s1[0] + s1[1];
	s5 = s3[0] + s3[1];
	if (s4 == s5) {
		cout << 1;
		cnt++;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	if (cnt == 1 && ((s1[2] == 'A' && (s3[2] == 'B' || s3[2] == 'C'))
	                 || (s1[2] == 'B' && (s3[2] == 'A' || s3[2] == 'C'))
	                 || (s1[2] == 'C' && (s3[2] == 'A' || s3[2] == 'B'))
	                 || (s1[2] == 'D' && (s3[2] == 'F')))
	        || (s1[2] == 'F' && (s3[2] == 'D'))) {
		cout << 1;
		cnt++;
	} else {
		cout << 0 << 0;
		return 0;
	}
	if (cnt == 2 && (s1[2] == 'A' && s3[2] == 'B'
	                 || s1[2] == 'B' && (s3[2] == 'A' || s3[2] == 'C')
	                 || s1[2] == 'C' && s3[2] == 'B'
	                 || s1[2] == 'D' && s3[2] == 'F'
	                 || s1[2] == 'F' && s3[2] == 'D')) {
		cout << 1;
		cnt++;
	} else {
		cout << 0;
	}
	return 0;
}