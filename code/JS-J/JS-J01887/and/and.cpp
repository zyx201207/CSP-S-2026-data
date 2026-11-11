#include <bits/stdc++.h>
using namespace std;

long long a[200005];
long long binn[32];

struct Node {
    long long d1;
    long long d2;
    long long m;
}c[200005];

long long fr(long long k) {
    if(k == 0) return 0;
    int r = 0;
    long long d = binn[r] - k;
    while(d <= 0) {
        r += 1;
        d = binn[r] - k;
    }
    // if(d == binn[r - 1]) r -= 1;
    return r;
}
bool tmp(Node a, Node b) {
    if(a.m == b.m) {
        if(a.d1 == b.d1) return a.d2 > b.d2;
        return a.d1 < b.d1;
    }
    return a.m > b.m;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    binn[0] = 1;
    for(int i = 1; i < 32; i++) {
        binn[i] = binn[i-1] * 2;
    }

    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            c[i].m = 0;
            c[i].d1 = 0;
            c[i].d2 = 0;
            continue;
        }
        c[i].m = fr(a[i]);
        c[i].d1 = binn[c[i].m] - a[i];
        c[i].d2 = a[i] - binn[c[i].m - 1];
        if(c[i].d1 == 0 || c[i].d2 == 0 || a[i] == binn[c[i].m]) {
            c[i].d1 = binn[c[i].m];
            c[i].d2 = binn[c[i].m - 1];
            c[i].m = 0;
        }

        // cout << a[i] << ": " << c[i].m << " " << c[i].d1 << " " << c[i].d2 << endl;
    }
    sort(c, c + n, tmp);
    long long ans = binn[c[0].m] - c[0].d1;
    // cout << binn[c[0].m] - c[0].d1 << ": " << c[0].m << " " << c[0].d1 << " " << c[0].d2 << endl;
    for(int i = 1; i < m; i++) {
        // cout << binn[c[i].m] - c[i].d1 << ": " << c[i].m << " " << c[i].d1 << " " << c[i].d2 << endl;
        ans = ans & (binn[c[i].m] - c[i].d1);
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
// ZZH39399