#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, b1, b2;
	char sa, sb;
	cin >> a1 >> a2 >> sa >> b1 >> b2 >> sb;
	if (a1 == b1) {
		cout << 1;
		if (a2 == b2) {
			cout << 1;
			if (sa >= 'A' && sa <= 'C' && sb >= 'A' && sb <= 'C' || sa >= 'D' && sa <= 'F' && sb >= 'D' && sb <= 'F')
				cout << 1;
			else
				cout << 0;
			if (sa == 'A' && sb == 'B' || sa == 'B' && sb == 'C' || sa == 'D' && sb == 'F')
				cout << 1;
			else
				cout << 0;
		} else
			cout << 0 << 0 << 0;
	} else
		cout << 0 << 0 << 0 << 0;
	return 0;
}