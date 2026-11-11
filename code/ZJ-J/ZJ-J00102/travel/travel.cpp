#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 10;
char c1[N], s1[N], c2[N], s2[N];

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if(c1[0] != c2[0] || c1[1] != c2[1])
		printf("0000\n");
	else if(s1[0] != s2[0] || s1[1] != s2[1])
		printf("1000\n");
	else if((s1[2] >= 'A' && s1[2] <= 'C') &&
	(s2[2] == 'D' || s2[2] == 'F'))
		printf("1100\n");
	else if((s1[2] == 'D' || s1[2] == 'F') &&
	(s2[2] >= 'A' && s2[2] <= 'C'))
		printf("1100\n");
	else if(s1[2] == s2[2] + 1 || s2[2] == s1[2] + 1)
		printf("1111\n");
	else if(s1[2] == 'D' && s2[2] == 'F')
		printf("1111\n");
	else if(s1[2] == 'F' && s2[2] == 'D')
		printf("1111\n");
	else printf("1110\n");
	return 0;
}
