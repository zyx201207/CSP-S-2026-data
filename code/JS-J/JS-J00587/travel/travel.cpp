#include <bits/stdc++.h>
using namespace std;
int c1, s1, c2, s2;
char s11, s22;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%d", &c1, &s1);
    s11 = getchar();
    scanf("%d%d", &c2, &s2);
    s22 = getchar();
    if (c1 != c2) {
        printf("0000");
        return 0;
    }
    else printf("1");
    if (s1 != s2) {
        printf("000");
        return 0;
    }
    else printf("1");
    if ((s11 >= 'A' && s11 <= 'C' && s22 >= 'A' && s22 <= 'C') || (s11 >= 'D' && s11 <= 'F' && s22 >= 'D' && s22 <= 'F')) {
        printf("1");
    }
    else {
        printf("00");
        return 0;
    }
    if (s11 + 1 == s22 || s11 - 1 == s22) printf("1");
    else printf("0");
    return 0;
}
