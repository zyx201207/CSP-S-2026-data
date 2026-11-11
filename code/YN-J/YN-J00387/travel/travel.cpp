#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string s3 = s1.substr(0, 2), s4 = s2.substr(0, 2);
	bool train = 0, line = 0, lr = 0, next = 0;
	if (c1 == c2) {
		train = 1;
		if (s3 == s4) {
			line = 1;
			if ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] < 'D' && s2[2] < 'D')) {
				lr = 1;
				if ((s1[2] + 1 == s2[2] ||  s1[2] - 1 == s2[2]) && (s1[2] + 1 != 'D' && s1[2] - 1 != 'C') ) {
					next = 1;
				}
			}
		}
	}
	cout << train << line << lr << next << endl;


	return 0;
}