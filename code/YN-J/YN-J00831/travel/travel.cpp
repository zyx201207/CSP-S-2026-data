#include <bits/stdc++.h>
using namespace std;
char s3[5], s4[5];

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2 ;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	for (int i = 0; i < 3; i++) {
		s3[i] = s1[i];
		s4[i] = s2[i];
	}
	if (c1 == c2) {
		a1 = 1;
		if (s3[0] == s4[0] && s3[1] == s4[1]) {
			a2 = 1;
			if (((s3[2] == 'A' || s3[2] == 'C' || s3[2] == 'B') && (s4[2] == 'A' || s4[2] == 'C' || s4[2] == 'B')) || (s3[2] == 'D'
			        && s4[2] == 'F')) {
				a3 = 1;
				if (s3[2] == 'D' && s4[2] == 'F') {
					a4 = 1;
				}
				if (s3[2] == 'A' && s4[2] == 'B') {
					a4 = 1;
				}
				if (s3[2] == 'B' && s4[2] == 'C') {
					a4 = 1;
				}
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}