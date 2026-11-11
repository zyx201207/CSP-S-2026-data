#include <bits/stdc++.h>
using namespace std;
long long c1, c2;
char s1[1001], s2[1001];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %s%d %s", &c1, s1, &c2, s2);
	if (c1 == c2) {
		printf("1");
		if (s1[0] == s2[0] and s1[1] == s2[1]) {
			printf("1");
			if ((s1[2] == 'F' and s2[2] == 'D') or (s1[2] == 'D' and s2[2] == 'F') or (s1[2] == 'A' and s2[2] == 'B')
			        or (s1[2] == 'B' and s2[2] == 'A') or (s1[2] == 'A' and s2[2] == 'C') or (s1[2] == 'C' and s2[2] == 'A')) {
				printf("1");
				if ((s1[2] == (s2[2] - 1)) or (s1[2] == (s2[2] + 1))) {
					printf("1\n");
					return 0;
				} else {
					printf("0\n");
					return 0;
				}
			} else {
				printf("00\n");
				return 0;
			}
		} else {
			printf("000\n");
			return 0;
		}
	} else {
		printf("0000\n");
		return 0;
	}

}