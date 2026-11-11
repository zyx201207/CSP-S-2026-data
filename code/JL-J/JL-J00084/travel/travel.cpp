
#include<bits/stdc++.h>

using namespace std;

int main () {
  char c1[15];
  char s1[15];
  char c2[15];
  char s2[15];
  freopen("travel.in", "r", stdin);
  freopen("travel.out","w", stdout);
    scanf("%s%s%s%s", c1, s1, c2, s2);
    if (c1[0] == c2[0] && c1[1] == c2[1])
        printf("1");
    else {
        printf("0000");
        return 0;
    }
    if (s1[0] == s2[0] && s1[1] == s2[1]) {
        printf("1");
        if (s1[2] >= 'D' && s2[2] >= 'D') {
            printf("1");
        }
        else
        if (s1[2] <= 'C' && s2[2] <= 'C')
            printf("1");
        else
            printf("0");
    }
    else {
        printf("000");
        return 0;
    }
    if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')) {
        printf("0");
        return 0;
	}
	if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
	    printf("1");
	    return 0;
	}
    else {
        if (abs(s1[2] - s2[2]) == 1)
            printf("1");
        else
            printf("0");
    }
return 0;}
