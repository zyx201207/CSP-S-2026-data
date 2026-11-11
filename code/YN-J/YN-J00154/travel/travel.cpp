#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string line, t;
	getline(cin, line);
	for (char ch : line)
		if (!isspace((unsigned char)ch))
			t += ch;
	string c1 = t.substr(0, 2), s1 = t.substr(2, 3), c2 = t.substr(5, 2), s2 = t.substr(7, 3);
	bool a = c1 == c2;
	bool b = a && s1.substr(0, 2) == s2.substr(0, 2);
	char x = s1[2], y = s2[2];
	string L = "ABC", R = "DF";
	bool lx = L.find(x) != string::npos, ly = L.find(y) != string::npos;
	bool c = b && ((lx && ly) || (!lx && !ly));
	bool d = false;
	if (c) {
		if (lx)
			d = abs((int)L.find(x) - (int)L.find(y)) == 1;
		else
			d = abs((int)R.find(x) - (int)R.find(y)) == 1;
	}
	cout << a << b << c << d << "\n";
	return 0;
}