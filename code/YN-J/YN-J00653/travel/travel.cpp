#include <iostream>

using namespace std;

const int N = 25;
char a[N];
char b[N];
int main() {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2];
	char b = s2[2];
	if (c1[0] = c2[0] && c2[1] == c1[1]) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			if (a == 'A' && b == 'B') {
				cout << "11";
			} else if (a == 'B' && b == 'A') {
				cout << "11";
			} else if (a == 'B' && b == 'C') {
				cout << "11";
			} else if (a == 'C' && b == 'B') {
				cout << "11";
			} else if (a == 'A' && b == 'C') {
				cout << "10";
			} else if (a == 'C' && b == 'A') {
				cout << "10";
			} else if (a == 'D' && b == 'F') {
				cout << "11";
			} else if (a == 'F' && b == 'D') {
				cout << "11";
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