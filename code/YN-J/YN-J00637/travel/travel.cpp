#include <iostream>
#include <string>
using namespace std;

int main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1 ;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	int a = s1[0];
	int b = s1[1];
	int c = s1[2];
	int d = s2[0];
	int e = s2[1];
	int f = s2[2];
	if (a == d && b == e) {
		cout << 1;
		if ((c <= 67 && f > 67) || (c > 67 && f <= 67)) {
			cout << 0;
		} else {
			cout << 1;
		}
		if ((c == 65 && f == 66) || (c == 66 && f == 67) ||
		        (c == 68 && f == 69) || (f == 65 && c == 66) ||
		        (f == 66 && c == 67) || (f == 68 && c == 69)) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0 << 0 << 0;
	}
	return 0;
}