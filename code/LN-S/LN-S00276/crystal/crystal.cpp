#include <bits/stdc++.h>
using namespace std;

char buf[1 << 20], *p1 = buf, *p2 = buf;
inline char gc() {
    if (p1 == p2) {
        p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin);
        if (p1 == p2) return EOF;
    }
    return *p1++;
}
template<typename T>
inline void read(T &t) {
    T f = 1, x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    t = f * x;
}

#define int long long
const int MAXN = 5e5 + 5;
int n, m, mpos, maxa = 0xc0c0c0c0c0c0c0c0, a[MAXN], answer;
int len, b[MAXN], cnt[MAXN], d[MAXN], s[MAXN];

bool cmp(int n1, int n2) {
    return n1 < n2;
}

bool check(int pos, int mid) {
    int tmp = 0;
    for (int i = mid; i < pos; i++) {
        tmp += (d[pos - 1] - d[i - 1]) * cnt[i];
    }
    return tmp <= m;
}

int bin(int pos) {
    int l = 1, r = pos, ans = pos, m_ = m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(pos, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (ans == 1) {
        return s[pos];
    }
    for (int i = pos - 1; i >= ans; i--) {
        m_ -= (d[pos - 1] - d[i - 1]) * cnt[i];
    }
    int extra = m_ / (d[pos - 1] - d[ans - 2]);
    return s[pos] - s[ans - 1] + extra;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        maxa = max(maxa, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        a[i] += maxa;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (a[i] ^ a[i - 1]) {
            if (len ^ 0) {
                d[len] = d[len - 1] + a[i] - a[i - 1];
            }
            b[++len] = a[i];
        }
        cnt[len]++;
    }
    for (int i = 1; i <= len; i++) {
        s[i] = s[i - 1] + cnt[i];
    }
    for (int i = 1; i <= len; i++) {
        int tmp = bin(i);
        answer = max(answer, tmp);
    }
    printf("%lld", answer);
    return 0;
}
