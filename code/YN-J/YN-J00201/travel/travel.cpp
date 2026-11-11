#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1;
	int s1;
	int c2;
	int s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2 && c1 != 01 && c2 != 02 && c1 <= 17 && c2 <= 17) {
		if (s1 == s2) {
			cout << '1111';
		} else {
			cout << '1000';
		}
	} else {
		cout << '0000';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
