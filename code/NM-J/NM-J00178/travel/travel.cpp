#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int val(char ch) {
	return (ch - 'A');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000" << "\n";
		return 0;
	}
	string p1 = s1.substr(0, 2), p2 = s2.substr(0, 2);
	if (p1 != p2) {
		cout << "1000" << "\n";
		return 0;
	}
	if (!((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))) {
		cout << "1100" << "\n";
		return 0;
	}
	int n1 = val(s1[2]), n2 = val(s2[2]);
	if (abs (n1 - n2) != 1) {
		cout << "1110" << "\n";
		return 0;
	}
	cout << "1111" << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
