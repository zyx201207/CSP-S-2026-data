#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	struct s {
		int a;
		char b;
	};
	s s1;
	s s2;
	cin >> c1 >> s1.a >> s1.b >> c2 >> s2.a >> s2.b;
	if (c1 == c2) {
		cout << '1';
		if (s1.a == s2.a) {
			cout << '1';
			if ((s1.b >= 'A' && s1.b <= 'C' && s2.b >= 'A' && s2.b <= 'C') || (s1.b >= 'D' && s1.b <= 'F' && s2.b >= 'D'&& s2.b <= 'F')) {
				cout << '1';
				if (s1.b + 1 == s2.b || s1.b - 1 == s2.b)
					cout << '1';
				else
					cout << '0';
			} else
				cout << '0' << '0';
		} else
			cout << '0' << '0' << '0';
	} else
		cout << '0' << '0' << '0' << '0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}