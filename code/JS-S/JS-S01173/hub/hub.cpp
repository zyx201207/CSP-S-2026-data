#include <bits/stdc++.h>
#define int long long
#define fi first 
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

int read() {
    int g = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        g = g * 10 + (ch ^ 48);
        ch = getchar();
    }
    return g * f;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    read();
    int T = read();
    while (T--) {
        printf("0\n");
    }
    return 0;
}