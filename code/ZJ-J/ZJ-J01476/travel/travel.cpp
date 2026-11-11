#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
char p, q;
int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf ("%d %d%c %d %d%c", &a, &b, &p, &c, &d, &q);
    if (a ^ c) return puts("0000"), 0;
    putchar('1');
    if (b ^ d) return puts("000"), 0;
    putchar('1');
    if (((p == 'A' || p == 'B' || p == 'C') &&
         (q == 'A' || q == 'B' || q == 'C')) ||
        ((p == 'D' || p == 'F') &&
         (q == 'D' || q == 'F')))
        putchar('1');
    else return puts("00"), 0;
    if ((p == 'A' && q == 'B') ||
        (p == 'B' && (q == 'A' || q == 'C')) ||
        (p == 'C' && q == 'B') ||
        (p == 'D' && q == 'F') ||
        (p == 'F' && q == 'D'))
        puts("1");
    else puts("0");
}