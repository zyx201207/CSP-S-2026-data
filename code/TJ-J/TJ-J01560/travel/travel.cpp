#include <bits/stdc++.h>
using namespace std;

void judge(bool judging) {
	if (judging)
		cout << 1;
	else
		cout << 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	bool first = (c1 == c2);
	bool second = (s1[0] == s2[0] && s1[1] == s2[1]);
	bool temp1 = (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C');
	bool temp2 = (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C');
	bool temp3 = (s1[2] == 'D' || s1[2] == 'F');
	bool temp4 = (s2[2] == 'D' || s2[2] == 'F');
	bool third = (temp1 && temp2 || temp3 && temp4);
	bool last = (abs(s1[2] - s2[2]) == 1);
	if (s1[2] == 'C' && s1[2] == 'D')
		last = false;

	if (first == false) {
		second = false;
		third = false;
		last = false;
	} else if (second == false) {
		third = false;
		last = false;
	} else if (third == false) {
		last = false;
	}

	judge(first);
	judge(second);
	judge(third);
	judge(last);
	return 0;
}