#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, s1;
	int a, b;
	cin >> a >> s >> b >> s1;
	if (a == b) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	int k = (s[0] - '0') + (s[1] - '0');
	int k1 = (s1[0] - '0') + (s1[1] - '0');
	if (k == k1) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	char t = s[2];
	char t1 = s1[2];
	if (t == 'A' || t == 'B' || t == 'C') {
		if (t1 == 'A' || t1 == 'B' || t1 == 'C') {
			cout << 1;
		} else {
			cout << 0 << 0;
			return 0;
		}
	} else {
		if (t1 == 'D' || t1 == 'F') {
			cout << 1;
		} else {
			cout << 0 << 0;
			return 0;
		}
	}
	if (t + 1 == t1 || t - 1 == t1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}