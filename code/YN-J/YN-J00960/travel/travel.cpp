#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[20], s1[30], c2[20], s2[30];
	scanf("%s", c1);
	scanf(" %s", s1);
	scanf(" %s", c2);
	scanf(" %s", s2);
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		printf("1");
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf("1");
			if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D'
			        && s2[2] <= 'F')) {
				printf("1");
				if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) {
					printf("1");
				} else {
					printf("0");
				}
			} else {
				printf("0");
				printf("0");
			}

		} else {
			printf("0");
			printf("0");
			printf("0");
		}
	} else {
		printf("0");
		printf("0");
		printf("0");
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}