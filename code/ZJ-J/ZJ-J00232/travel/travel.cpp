#include <iostream>
#define int long long
using namespace std;
int c1, c2;
string s1, s2;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string h1 = "" + s1[0] + s1[1], h2 = "" + s2[0] + s2[1];
	char l1 = s1[2], l2 = s2[2];
	if (c1 != c2)
		cout << "0000";
	else if (h1 != h2)
		cout << "1000";
	else if (('A'<= l1 && 'C' >= l1 && 'D' <= l2 && 'E' >= l2) || ('A'<= l2 && 'C' >= l2 && 'D' <= l2 && 'E' >= l2))
		cout << "1100";
	else if (abs(l1 - l2) != 1 || (l1 == 'C' && l2 == 'D') || (l1 == 'D' && l2 == 'C'))
		cout << "1110";
	else
		cout << "1111";
	return 0;
}