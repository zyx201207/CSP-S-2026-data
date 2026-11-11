#include <bits/stdc++.h>
using namespace std;

char s1[67], s2[67];
char c1[67], c2[67];
bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%s %s", c1 + 1, s1 + 1);
	scanf("%s %s", c2 + 1, s2 + 1);
	
	if (c1[1] == c2[1] && c1[2] == c2[2]) {
		printf("1");
		f1 = 1;
	} else {
		printf("0");
	}
	
	if (s1[2] == s2[2] && s1[1] == s2[1] && f1) {
		printf("1");
		f2 = 1;
	}else {
		printf("0");
	}
	
	if ((((s1[3] >= 'A' && s1[3] <= 'C') && (s2[3] >= 'A' && s2[3] <= 'C')) || ((s1[3] >= 'D' && s1[3] <= 'F') && (s2[3] >= 'D' && s2[3] <= 'F'))) && f2) {
		printf("1");
		f3 = 1;
	}else {
		printf("0");
	}
	
	bool a = 1, b = 1;
	if (s1[3] == 'C' && s2[3] == 'D') a = 0;
	if (s1[3] == 'D' && s2[3] == 'D') b = 0;
	
	if (((s1[3] + 1 == s2[3]) || (s2[3] + 1 == s1[3])) && a && b && f3){
		printf("1");
	}else {
		printf("0");
	}
	printf("\n");
	return 0;
}
