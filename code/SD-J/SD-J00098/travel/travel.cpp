#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int num_r = (s1[0] - '0') * 10 + s1[1];
	int num_x = (s2[0] - '0') * 10 + s2[1];
	// R车厢， R座位， X车厢，X座位 
	bool b[]{false, false, false, false};
	if (c1 == c2) {
		b[0] = true;
		if (num_x == num_r) {
			b[1] = true;
			if (
				(s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')
			) {
				b[2] = true;
				if (abs(s1[2] - s2[2]) == 1) {
					b[3] = true;
				}
			}
		}	
	}
	for (int i = 0; i < 4; i++){
		putchar(b[i] + '0');
	}
	
	return 0;
}
