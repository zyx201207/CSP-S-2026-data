#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	for (int i = 1; i <= 4; i++) {
		if (c1 == c2) {
			cout << "1";
		}
		int n = s1 % 10;
		int m = s2 % 10;
		int a = n / 10;
		int b = m / 10;
		if (a == b) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}