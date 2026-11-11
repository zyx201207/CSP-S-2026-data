#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define gc getchar_unlocked
#define readT int

inline readT rd() {
    readT x = 0; int ch = gc(), f = 1;
    for (; ! isdigit(ch); ch = gc()) {if (ch == '-') {f = -1;}}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}

constexpr int N = 2e5 + 10;

int n;
int a[N], c[N];

inline void sol() {
    n = rd();
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
        c[i] = gc() - 48;
    }

    int i = 1, j = n;
    ll res = 0;
    while (i < j) {
        if (c[i] == c[j]) {
            if (a[i] < a[j]) a[j] -= a[i++];
            else if (a[i] > a[j]) a[i] -= a[j--];
            else ++ i, -- j;
        }
        else {
            if (a[i] < a[j]) {
                res += a[i];
                a[j] -= a[i];
                ++ i;
            }
            else if (a[i] > a[j]) {
                res += a[j];
                a[i] -= a[j];
                -- j;
            }
            else {
                res += a[i];
                ++ i, -- j;
            }
        }
    }

    cout << res;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int qwq = 1;
    // qwq = rd();
    while (qwq --) {
        sol();
    }

    return 0;
}

// freeopen fireopen freepon
// freopen("", 'w', stdin)
// stderr 'r'
// <bits\stdc++.h>
// main main main main main main main main main main main main 
// mian mian mian qwq awa # # # # # # # # # # # # # # # # # # # # # # # #

/*

aabbc

2a 2b c

a 2b   1

 b      1

++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;++rp;
*/