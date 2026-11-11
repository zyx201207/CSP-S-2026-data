#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen('travelin', 'r', 'stdin');
	freopen('travelout', 'w', 'stdout');

	int c1, s1, c2, s2;
	cin >>  c1 >> s1 >> c2 >> s2;

	for (int i = 0; i < 2; i++) {

		if (c1 == c2 ) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}

	for (int j = 0; j < 2; j++) {

		if (s1 == s2 ) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}

	fclose(stdin)fclose(stdout);
	return 0;
}
