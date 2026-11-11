#include<bits/stdc++.h>
using namespace std;

char cc1[10], ss1[10], cc2[10], ss2[10];

bool check(char a, char b) {
    if (a > b)
        swap(a, b);
    return (a == 'A' && b == 'B') || (a == 'A' && b == 'C') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F');
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", cc1 + 1, ss1 + 1, cc2 + 1, ss2 + 1);
    if (strcmp(cc1 + 1, cc2 + 1) == 0) {
        printf("1");
        if (ss1[1] == ss2[1] && ss1[2] == ss2[2]) {
            printf("1");
            if (check(ss1[3], ss2[3])) {
                printf("1");
                char a = ss1[3], b = ss2[3];
                if (a > b)
                    swap(a, b);
                if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) {
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
    return 0;
}
