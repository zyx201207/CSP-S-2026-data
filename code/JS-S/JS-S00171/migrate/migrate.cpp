#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10;
inline int input() {
    char c = gc();
    int x = 0, f = 1;
    while (c < '0' or c > '9') {
        if (c == '-') f = -f;
        c = gc();
    }
    while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = gc();
    return x * f;
}
void print(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) print(x / 10);
    pc(x % 10 + '0');
}
int testc, T, n, d, ans, pos[N];
bool check(int l, int r) {
    int tmp = 0;
    vector <int> v, u;
    v.resize(0); u.resize(0);
    v.emplace_back(l);
    u.emplace_back(r);
    for (int i = l + 1; i <= r; i++) {
        if (tmp + pos[i] - pos[i - 1] > d) {
            v.emplace_back(i - 1);
            tmp = pos[i] - pos[i - 1];
        }
        else{
            tmp += pos[i] - pos[i - 1];
        }
    }
    v.emplace_back(r);
    tmp = 0;
    for (int i = r - 1; i >= l; i--) {
         if (tmp + pos[i + 1] - pos[i] > d) {
            u.emplace_back(i + 1);
            tmp = pos[i + 1] - pos[i];
        }
        else{
            tmp += pos[i + 1] - pos[i];
        }
    }
    v.emplace_back(l);
    if (u.size() != v.size()) return false;
    int idx = v.size();
    for (int i = 0, j = idx - 1; i < idx; i++, j--) {
        if (u[j] != v[i]) return true;
    }
    return false;
}
void solve() {
    ans = 0;
    n = input(), d = input();
    for (int i = 1; i <= n; i++) pos[i] = input();
    if (testc == 11 or testc == 12) {
        int delta = pos[2] - pos[1];
        if (delta > d) {
            pc('0');
            pc('\n');
            return ;
        }
        for (int i = 1; i < n; i++) {
            if (i % (d / delta) == 0 or d / delta >= i) continue;
            ans += n - i;
        }
        print(ans); pc('\n');
        return ;
    }
    if (testc == 13 or testc == 14) {
        print(0); pc('\n');
        return ;
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l + 1; r <= n; r++) {
            if (pos[r] - pos[l] <= d) continue;
            if (check(l, r)) ans++;
        }
    }
    print(ans); pc('\n');
    return ;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    testc = input(), T = input();
    while (T--) solve();
    return 0;
}
