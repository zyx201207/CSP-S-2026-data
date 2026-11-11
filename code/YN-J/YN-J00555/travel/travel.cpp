#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[5], s1[5], c2[5], s2[5], a[5] = {0, 0, 0, 0};
	scanf("%s %s %s %s", c1, s1, c2, s2);
	if (!strcmp(c1, c2)) {
		printf("1");
		if (s1[0] == s2[0] && s2[1] == s1[1]) {
			printf("1");
			char x = max(s1[2], s2[2]), n = min(s1[2], s2[2]);
			if (x - n <= 2 && (x <= 'C' || n >= 'D')) {
				printf("1");
				if (x - n == 1) {
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