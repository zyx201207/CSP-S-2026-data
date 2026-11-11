#include <bits/stdc++.h>
#define int long long
#define fi first 
#define se second
#define pb push_back
using namespace std;
const int N = 2e6 + 5;
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
int n, d, x[N], ans, c;
int a[N], b[N], ta, tb;
// bool check(int f, int s) {
//     int i = f;
//     ta = tb = 0;
    // a[++ta] = f;
    // // cout << "1" << endl;
    // while (i < s) {
    //     int r = i + 1;
    //     if (abs(x[r] - x[i]) > d) return 0;
    //     while (r <= s && abs(x[r] - x[i]) <= d) r++;
    //     r--, a[++ta] = r, i = r;
    // }
//     // cout << "2" << endl;
//     i = s, b[++tb] = i;
//     while (i > f) {
//         int l = i - 1;
//         if (abs(x[l] - x[i]) > d) return 0;
//         while (l >= f && abs(x[i] - x[l]) <= d) l--;
//         l++, b[++tb] = l, i = l;
//     }
//     // cout << 3 << endl;
//     if (ta != tb || ta == 0) return 0;
//     // for (int i = 1; i <= ta; i++) cout << a[i] << " ";
//     // cout << endl;
//     // for (int i = 1; i <= tb; i++) cout << b[i] << " ";
//     // cout << endl;
//     bool same = 1;
//     for (int i = 1; i <= ta; i++) {
//         if (a[i] != b[ta - i + 1]) same = 0;
//     }
//     if (same) return 0;
//     for (int i = 2; i < ta; i++) {
//         int now = a[i];
//         if (abs(x[now + 1] - x[now - 1]) <= d) return 0;
//     }
//     for (int i = tb - 1; i > 1; i--) {
//         int now = b[i];
//         if (abs(x[now + 1] - x[now - 1]) <= d) return 0;
//     }
//     return 1;
// }
bool check(int f, int s) {
    for (int i = f; i < s; i++) {
        if (abs(x[i + 1] - x[i]) > d) return 0;
    }
    int i = f, cnt = 1;
    ta = 0;
    a[++ta] = f;
    while (i < s) {
        int r = i + 1;
        if (abs(x[r] - x[i]) > d) return 0;
        while (r <= s && abs(x[r] - x[i]) <= d) r++;
        r--, a[++ta] = r, i = r;
    }
    for (int i = 2; i < ta; i++) {
        int now = a[i], lst = a[i - 1], nxt = a[i + 1];
        while (now > lst && abs(x[now] - x[nxt]) <= d) now--;
        now++;
        cnt += a[i] - now;
        if (cnt > 2) return 0;
    }
    return cnt == 2;
}
void solve() {
    n = read(), d = read(), ans = 0;
    for (int i = 1; i <= n; i++) x[i] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            // cout << i << " " << j << endl;
            if (check(i, j)) {
                // cout << i << " " << j << endl; 
            ans++;}
        }
    }
    printf("%lld\n", ans);
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read();
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}
/*
17:29 I dont know how to debug this problem!!!!!!!!!!
I have thought for 1h!!!!
now -> 144pts
Should I continue thinking about this question?
Too difficult Too difficultToo difficult Too difficult Too difficult Too difficult
// freopen (bushi
I wanna see myself in Human Confused Action OVO

17:37 I just got 24 pts!
now -> 168pts
*/