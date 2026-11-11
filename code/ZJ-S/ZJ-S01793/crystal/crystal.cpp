#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
const int IS = 1 << 20, OS = 1 << 19;
char in_buf[IS], out_buf[OS];
char *in_p = in_buf, *in_q = in_buf, *out_q = out_buf, *const out_end = out_buf + OS;
inline char getch() {
    if(in_p == in_q) {
        in_q = (in_p = in_buf) + fread(in_buf, 1, IS, stdin);
        if(in_p == in_q) return 0;
    }
    return *in_p++;
}
inline void reader(char& c) {do c = getch(); while(c <= ' ');}
template<class T>
inline void reader(T& x) {
    char c, neg = '+';
    unsigned long long ux = 0;
    reader(c);
    if(c == '-') neg = '-', c = getch();
    do {
        ux = ux * 10 + c - '0';
        c = getch();
    }while(c >= '0' && c <= '9');
    if(neg == '+') x = (T)ux;
    else x = -(T)ux;
}
inline void reader(char* s) {
    reader(*s);
    do *++s = getch(); while(*s > ' ');
    *s = '\0';
}
template<class ... Args>
inline void read(Args& ... args) {
	(void)initializer_list<int> {(reader(args), 0) ...};
}
inline void flush_out() {
    if(out_q != out_buf) {
        fwrite(out_buf, 1, out_q - out_buf, stdout);
        out_q = out_buf;
    }
}
inline void putch(char c) {
    if(out_q == out_end) flush_out();
    *out_q++ = c;
}
inline void writer(char c) {putch(c);}
template<class T>
inline void writer(T x) {
    static char buf[24];
    unsigned long long ux;
    if(x >= 0) ux = x;
    else {
        putch('-');
        ux = -(unsigned long long)x;
    }
    int len = 0;
    do {
        buf[len++] = ux % 10 + '0';
        ux /= 10;
    }while(ux > 0);
    while(len--) putch(buf[len]);
}
inline void writer(const char* s) {do putch(*s++); while(*s);}
template<class ... Args>
inline void write(const Args& ... args) {
	(void)initializer_list<int> {(writer(args), 0) ...};
}

constexpr int UN = 5e5 + 4;
int n, ans;
ll m, a[UN], pre[UN];

inline bool check(int l, int r) {
    return pre[r] - pre[l - 1] + m >= a[r] * (r - l + 1);
}

int main() {
	atexit(flush_out);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n, m);
    for(int i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) pre[i] =pre[i - 1] + a[i];
    int p = 1;
    for(int i = 1; i <= n; ++i) {
        while(!check(p, i)) ++p;
        ans = max(ans, i - p + 1);
    }
    write(ans);
    return 0;
}
//[l, r]: (sum(i = l to r)a[i] + m)/ len >= a[r]
