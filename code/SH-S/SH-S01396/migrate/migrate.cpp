#include <bits/stdc++.h>

namespace FastIO {
    constexpr int SIZE = 1 << 20;
    static char ibuf[SIZE], *p1 = ibuf, *p2 = ibuf, obuf[SIZE], *p3 = obuf, *p4 = obuf + SIZE;
    char getc() { if (p1 == p2) p1 = ibuf, p2 = ibuf + fread(ibuf,1,SIZE,stdin); return p1 == p2 ? EOF : *p1++; }
    void flush() { fwrite(obuf,1,p3-obuf,stdout), p3 = obuf; }
    void putc(char c) { if (p3 == p4) flush(); *p3++ = c; }
    template <typename T> T readI() { T x = 0, f = 1; char c = getc(); for ( ; c < '0' || c > '9'; c = getc()) if (c == '-') f = -1; for ( ; c >= '0' && c <= '9'; c = getc()) x = x*10 + c-'0'; return x*f; }
    template <typename T> void print(T x) { static char StkPut[65]; int TOP = 0; if (x < 0) putc('-'), x = -x; do StkPut[++TOP] = x%10 + '0', x /= 10; while (x); while (TOP) putc(StkPut[TOP--]); }
    template <typename T> void println(T x) { print(x), putc('\n'); }
    struct Flush { ~Flush() { flush(); } } _;
}

namespace Solution {
    using FastIO :: readI;
    using FastIO :: println;
    #define read readI<long long>

    constexpr int N = 2e6+3;
    int n;
    long long d, x[N];

    template <typename T> T gcd(T a, T b) {
        if (!b) return a;
        return gcd<T>(b,a%b);
    }

    namespace Subtask10 {
        void Subtask10() {
            long long g = x[2] - x[1];
            for (int i = 2; i < n; i++) g = gcd(g,x[i+1]-x[i]);
            long long b = d / g, len = g * (2 * b - 1);
            if (b <= 1) { println(0); return; }
            long long ans = std::max(0ll,n-len);
            std::vector <std::pair <long long,long long>> intervals;
            for (int i = 1; i < n; i++) {
                long long g0 = x[i+1] - x[i];
                if (g0 == g) continue;
                if (g0 > d) { ans--; continue; }
                long long l = x[i] + g, r = x[i+1] - g;
                long long L = std::max(x[1],l-len), R = std::min(x[n]-len,r);
                if (intervals.empty() || intervals.back().second < L) intervals.emplace_back(L,R);
                else intervals[(int)intervals.size()-1].second = R;
            }
            for (auto A : intervals) {
                long long L = A.first, R = A.second;
                ans -= (R - L + 1) / g;
            }
            println(ans);
        }
    }

    namespace SubtaskA {
        void SubtaskA() {
            long long g = x[2] - x[1], b = d / g;
            if (b <= 1) { println(0); return; }
            long long ans = std::max(0ll,n-2*b+1);
            println(ans);
        }
    }

    void Solve(int c) {
    	memset(x,0,sizeof(x));
        n = readI<int>(), d = read();
        for (int i = 1; i <= n; i++) x[i] = read();

        if (c <= 10) Subtask10::Subtask10();
        else if (c <= 12) SubtaskA::SubtaskA();
    }
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c = FastIO::readI<int>(), t = FastIO::readI<int>();
    while (t--) Solution::Solve(c);
}