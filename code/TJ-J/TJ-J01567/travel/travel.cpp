#include <bits/stdc++.h>
using namespace std;
int n1, n2, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
string c1, c2;
string s1, s2;
char t1, t2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 0; i < c1.size(); i++) {
		if (c1[i] > '0' && c1[i] <= '9') {
			n1 = c1[i] - '0';
		}
		if (c2[i] > '0' && c2[i] <= '9') {
			n2 = c2[i] - '0';
		}
	}
	if (n1 == n2)
		f1 = 1;
	else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] > '0' && s1[i] <= '9') {
			n1 = s1[i] - '0';
		}
		if (s2[i] > '0' && s2[i] <= '9') {
			n2 = s2[i] - '0';
		}
		if (s1[i] >= 'A' && s1[i] <= 'F') {
			t1 = s1[i];
		}
		if (s2[i] >= 'A' && s2[i] <= 'F') {
			t2 = s2[i];
		}
	}
	if (n1 == n2)
		f2 = 1;
	else {
		cout << "1000";
		return 0;
	}
	if (((t1 == 'A' && t2 == 'B') || (t1 == 'A' && t2 == 'C') || (t1 == 'B' && t2 == 'C') || (t1 == 'D' && t2 == 'F'))
	        || ((t2 == 'A' && t1 == 'B') || (t2 == 'A' && t1 == 'C') || (t2 == 'B' && t1 == 'C') || (t2 == 'D' && t1 == 'F'))) {
		f3 = 1;
	} else {
		cout << "1100";
		return 0;
	}
	if (((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'C') || (t1 == 'D' && t2 == 'F')) || ((t2 == 'A' && t1 == 'B')
	        || (t2 == 'B' && t1 == 'C') || (t2 == 'D' && t1 == 'F'))) {
		f4 = 1;
	}
	cout << f1 << f2 << f3 << f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}