#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel ", "r"stdin);
	freopen("travel ", "w"stdout);

	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	for (int i = 1; i <= 17 && i != 01 || 16; i++) {
		c1 = c2;
		cout <<   1 ;
		if (c1 != c2) {
			cout << 0 ;
		}

	}
	for (int i = 1; i <= 18; i++) {
		s1 = s2;
		cout << 1;
		if (s1 != s2) {
			cout << 0;
		}
	}
	


	return 0;
}
fclose(stdin);
fclose(stdout);
