#include<bits/stdc++.h>
using namespace std;

char s1[50], s2[50], c1[50], c2[50]; 
int a[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	if(c1[1] == c2[1] && c1[2] == c2[2])
		a[1] = 1;
	if(a[1] == 1 && s1[1] == s2[1] && s1[2] == s2[2])
		a[2] = 1;
	if(((a[2] == 1 && (s1[3] == 'A' || s1[3] == 'B' || s1[3] == 'C') && (s2[3] == 'A' || s2[3] == 'B' || s2[3] == 'C')))
	|| ((s1[3] == 'D' || s1[3] == 'E') && (s2[3] == 'D' || s2[3] == 'E')))
		a[3] = 1;
	if(a[3] == 1 && ((s1[3] + 1 == s2[3]) || (s1[3] == s2[3] + 1)))
		a[4] = 1;
	for(int i = 1; i <= 4; i++)
		printf("%d", a[i]);
	return 0;
}
