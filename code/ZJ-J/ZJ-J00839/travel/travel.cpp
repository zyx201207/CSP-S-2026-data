#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string c1, s1, c2, s2;
bool isSameSide() {
	bool side1 = 0, side2 = 0;
	string l1 = s1.substr(2, 1), l2 = s2.substr(2, 1);
	if (l1 == "D" || l1 == "F") side1 = 1;
	if (l2 == "D" || l2 == "F") side2 = 1;
	return side1 == side2;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool f1 = 0;
	if (c1 == c2) {
		f1 = 1;
		cout << 1;
	} else cout << 0;
	bool f2 = 0;
	if (f1 && s1.substr(0, 2) == s2.substr(0, 2)) {
		f2 = 1;
		cout << 1;
	}
	else cout << 0;
	bool f3 = 0;
	if (f2 && isSameSide()) {
		f3 = 1;
		cout << 1;
	} else cout << 0;
	if (f3 && abs(int(s2.substr(2, 1)[0]) - int(s1.substr(2, 1)[0])) == 1) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}