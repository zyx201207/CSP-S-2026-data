#include <iostream>
#include <string>

using namespace std;
string c1, s1, c2, s2;
int r1, r2, r3, r4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	if (c1 == c2) {
		r1++;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			r2++;
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				r3++;
				if (s1[2] == 'F') s1[2] = 'E';
				if (s2[2] == 'F') s2[2] = 'E';
				if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) r4++;
			}
		}
	}
	
	cout << r1 << r2 << r3 << r4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
