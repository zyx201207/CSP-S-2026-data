#include<iostream>
#include<cmath>

using namespace std;
bool ifp(string s1, string s2) {
	if (s1[0] == s2[0] && s1[1] == s2[1]) return true;
	return false;
}
bool ifgd(string s1, string s2) {
	if (s1[2] <= 'C' && s2[2] <= 'C') return true;
	else if (s1[2] > 'C' && s2[2] > 'C') return true;
	return false;
}
bool ifxl(string s1, string s2) {
	if (s1[2] == 'D' && s2[2] == 'F') return true;
	if (s1[2] == 'F' && s2[2] == 'D') return true;
	if (s1[2] == 'A' && s2[2] == 'B') return true;
	if (s1[2] == 'B' && s2[2] == 'A') return true;
	if (s1[2] == 'B' && s2[2] == 'C') return true;
	if (s1[2] == 'C' && s2[2] == 'B') return true;
	return false;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int f1 = 0, f2 = 0, f3 = 0;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) f1 = 1;
	if (f1 && ifp(s1, s2)) f2 = 1;
	if (f2 && ifgd(s1, s2)) f3 = 1;
	cout << f1 << f2 << f3;
	if (f3 && ifxl(s1, s2)) cout << 1;
	else cout << 0;
	return 0;
}
