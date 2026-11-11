#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a1, b1, a2, b2;
char ch1, ch2, c1[9], s1[9], c2[9], s2[9];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    if (c1[1] == c2[1] && c1[2] == c2[2])
        printf("1");
    else {
        printf("0000");
        return 0;
    }
    if (s1[1] == s2[1] && s1[2] == s2[2])
        printf("1");
    else {
        printf("000");
        return 0;
    }
    bool side1 = 0, side2 = 0;
    if (s1[3] == 'D' || s1[3] == 'F')
        side1 = 1;
    if (s2[3] == 'D' || s2[3] == 'F')
        side2 = 1;
    if (side1 == side2)
        printf("1");
    else {
        printf("00");
        return 0;
    }
    if (side1 || abs(s1[3] - s2[3]) == 1)
        printf("1");
    else
        printf("0");
}

