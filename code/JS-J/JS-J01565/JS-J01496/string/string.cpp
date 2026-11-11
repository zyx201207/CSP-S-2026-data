#include "bits/stdc++.h"
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll n, a[N];
char s[N];

inline ll read() {
    ll x = 0, f = 1;
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
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
        char ch = getchar();
        while (ch < 'a' || ch > 'z') {
            ch = getchar();
        }
        s[i] = ch;
    }
    int it1 = 1, it2 = n;
    ll ans = 0;
    while (it1 < it2) {
        if (s[it1] != s[it2]) {
            if (a[it1] == a[it2]) {
                ans += a[it1];
                it1 ++, it2 --;
            }else {
                if (a[it1] > a[it2]) {
                    a[it1] -= a[it2];
                    ans += a[it2];
                    it2 --;
                }else {
                    a[it2] -= a[it1];
                    ans += a[it1];
                    it1 ++;
                }
            }
        }else {
            if (a[it1] == a[it2]) {
                it1 ++, it2 --;
            }else {
                if (a[it1] > a[it2]) {
                    a[it1] -= a[it2];
                    it2 --;
                }else {
                    a[it2] -= a[it1];
                    it1 ++;
                }
            }
        }
    }
    printf("%lld", ans);
}
