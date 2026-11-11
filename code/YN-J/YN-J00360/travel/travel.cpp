#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
char num1 = '0', num2 = '0', num3 = '0', num4 = '0';

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 == c3) {
		num1 = '1';
		if (c2[0] == c4[0] && c2[1] == c4[1]) {
			num2 = '1';
			if ((c2[2] <= 'C' && c4[2] <= 'C') || (c2[2] > 'C' && c4[2] > 'C')) {
				num3 = '1';
				if (((int)c2[2] == (int)c4[2] + 1) || ((int)c2[2] == (int)c4[2] - 1)) {
					num4 = '1';
				}
			}
		}
	}
	printf("%c%c%c%c", num1, num2, num3, num4);
	return 0;
}