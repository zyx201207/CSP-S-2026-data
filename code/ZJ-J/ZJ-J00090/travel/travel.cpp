#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char s[10], t[10], a[10], b[10];

bool check1(char c, char d) {
    return (((c == 'A' || c == 'B' || c == 'C') && (d == 'A' || d == 'B' || d == 'C'))
        || ((c == 'D' || c == 'F') && (d == 'D' || d == 'F')));
}

bool check2(char c, char d) {
    if (d < c)
        swap(c, d);
    return (((c == 'A') && (d == 'B')) || ((c == 'B') && (d == 'C')) || ((c == 'D') && (d == 'F')));
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", s + 1, a + 1, t + 1, b + 1);
    if (s[1] == t[1] && s[2] == t[2]) {
        printf("1");
        if (a[1] == b[1] && a[2] == b[2]) {
            printf("1");
            if (check1(a[3], b[3])) {
                printf("1");
                if (check2(a[3], b[3]))
                    printf("1\n");
                else
                    printf("0\n");
            }
            else
                printf("00\n");
        }
        else
            printf("000\n");
    }
    else
        printf("0000\n");
    return 0;
}
