#include "bits/stdc++.h"
#define ll long long
using namespace std;

string c1, c2, s1, s2;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        putchar('1');
        if (s1[0] == s1[0] && s1[1] == s2[1]) {
            putchar('1');
            if (s1[2] <= 'C' && s2[2] <= 'C') {
                putchar('1');
                if (abs(s1[2] - s2[2]) == 1) {
                    putchar('1');
                }else {
                    putchar('0');
                }
            }   else {
                if (s1[2] >= 'D' && s2[2] >= 'D') {
                    putchar('1');
                    if (abs(s1[2] - s2[2]) == 1) {
                        putchar('1');
                    } else {
                        putchar('0');
                    }
                } else {
                    putchar('0');
                    putchar('0');
                }
            }
        }else {
            putchar('0');
            putchar('0');
            putchar('0');
        }
    }else {
        putchar('0');
        putchar('0');
        putchar('0');
        putchar('0');
    }
}
