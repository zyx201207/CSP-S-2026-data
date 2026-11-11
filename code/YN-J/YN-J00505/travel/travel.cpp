#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r" std);
	freopen("travel.out", "w" std);
	int c1, c2, a;
	cin >> c1;
	char s1[2];
	cin >> s1;

	cin >> c2;
	char s2[2];
	cin >> s2;
	if (c1 == c2) {
		cout << "1";
		for (int i = 0; i <= 2; i++) {
			if (s1[i] >= 'A' && s1[i] <= 'F' && s2[i] >= 'A' && s2[i] <= 'F') {
				break;
			}
			if (s1[i] == s2[i]) {
				a = 1;
			} else {
				a = 0;
			}
		}
		cout << a;
	} else {
		cout << "0000";
	}

	return 0;
}