#include <bits/stdc++.h>
using namespace std;
#define int long long
#define get getchar
inline int read() {
    int x = 0, f = 1;
    char ch = get();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -f;
        ch = get();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - 48);
        ch = get();
    }
    return x * f;
}
int a[200005], n, c[200005];
char b[200005], d[200005];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        cin >> b[i];
        c[n-i+1] = a[i];
        d[n-i+1] = b[i];
    }
    int j = 1, i = 1, ans = 0;
    while(i <= n && j <= n) {
        while(a[i] > c[j]) {
            a[i] -= c[j];
            if(b[i] != d[j]) {
                ans += c[j];
            }
            j++;
        }
        while(a[i] <= c[j]) {
            c[j] -= a[i];
            if(b[i] != d[j]) {
                ans += a[i];
            }
            i++;
        }
    }
    cout << ans / 2;
    return 0;
}
