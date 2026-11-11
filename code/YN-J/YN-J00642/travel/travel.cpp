#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
	if (a == 'D' && b == 'F')
		return true;
	else if (a == 'F' && b == 'D')
		return true;
	else if (a == 'A' && b == 'B')
		return true;
	else if (a == 'B' && b == 'A')
		return true;
	else if (a == 'A' && b == 'C')
		return true;
	else if (a == 'C' && b == 'A')
		return true;
	else if (a == 'B' && b == 'C')
		return true;
	else if (a == 'C' && b == 'B')
		return true;
	else
		return false;
}

bool cmp2(char a, char b) {
	if (a == 'D' && b == 'F')
		return true;
	else if (a == 'F' && b == 'D')
		return true;
	else if (a == 'A' && b == 'B')
		return true;
	else if (a == 'B' && b == 'A')
		return true;
	else if (a == 'B' && b == 'C')
		return true;
	else if (a == 'C' && b == 'B')
		return true;
	else
		return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a[2], b[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	if (a[0] == b[0]) {
		cout << "1";
		if (a[1][0] == b[1][0] && a[1][1] == b[1][1]) {
			cout << "1";
			if (cmp(a[1][2], b[1][2])) {
				cout << "1";
				if (cmp2(a[1][2], b[1][2]))
					cout << "1";
				else
					cout << "0";
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}