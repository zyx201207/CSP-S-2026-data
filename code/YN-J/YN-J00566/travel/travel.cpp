#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int p1, p2;
	if (c1 == c2) {
		printf("1");
		p1 = s1[0] * 10 + s1[1];
		p2 = s2[0] * 10 + s2[1];
		if (p1 == p2) {
			printf("1");
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
				printf("1");
				if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] || s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1) {
					printf("1");
				} else {
					printf("0");
				}
			} else {
				printf("00");
			}
		} else {
			printf("000");
		}
	} else {
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}