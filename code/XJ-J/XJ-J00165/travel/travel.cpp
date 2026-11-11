#include<bits/stdc++.h>

using namespace std;

int n, m;
char s1[5], s2[5];

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %s %d %s", &n, s1 + 1, &m, s2 + 1);
	if(n != m)
		printf("0000\n");
	else
		if(s1[1] != s2[1] || s1[2] != s2[2])
			printf("1000\n");
		else
			if(s1[3] == 'C' && s2[3] == 'D')
				printf("1100\n");
			else
				if(s1[3] + 1 != s2[3])
					printf("1110\n");
				else
					printf("1111\n");
	return 0;
}
