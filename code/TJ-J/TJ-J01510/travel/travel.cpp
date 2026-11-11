#include<bits/stdc++.h>
using namespace std;

char s1[5], c1[5], s2[5], c2[5]; 

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s %s %s %s", s1 + 1, c1 + 1, s2 + 1, c2 + 1);
	bool f = true;
	for (int i = 1; i <= 2; i++)
		if (s1[i] != s2[i])
			f = false;
	if (f) {
		bool d = true;
		printf("1");
		for (int i = 1; i <= 2; i++)
			if (c1[i] != c2[i]) 
				d = false;
		if (d) {
			printf("1");
			char x = c1[3], y = c2[3];
			if ((x <= 'D' && y <= 'D') || (x > 'D' && y > 'D')) {
				printf("1");
				if (x - y == 1 || x - y == -1)
					printf("1");
				else
					printf("0");
			}
			else
				printf("00");
		}
		else {
			printf("000");
		}
	}
	else {
		printf("0000");
	}
	return 0;
}

