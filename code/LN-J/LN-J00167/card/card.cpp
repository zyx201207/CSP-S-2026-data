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
    while (c > '9' || c < '0') {
        if (c == '-') f = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    t = f * x;
}

const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int n, m, a[MAXN];
int last[MAXM], cnt[MAXM];
int st[MAXN], tail = 0;

inline bool __empty() {
    return tail == 0;
}

inline void __push(int x) {
    st[++tail] = x;
}

inline int __top() {
    if (!__empty()) {
        return st[tail];
    }
    return EOF;
}

inline void __pop() {
    if (!__empty()) {
        tail--;
    }
}

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        memset(last, 0, sizeof(last));
        for (int j = i; j <= n; j++) {
            if (last[a[j]]) {
                while (__top() ^ a[j]) {
                    last[__top()] = 0;
                    __pop();
                }
                __pop();
            }
            __push(a[j]);
            last[a[j]] = j;
        }
        while (!__empty()) {
            cnt[__top()]++;
            __pop();
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}
