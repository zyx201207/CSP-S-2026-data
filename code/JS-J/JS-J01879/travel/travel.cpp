#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ui128 = __uint128_t;
#define amin(x, y) x = min(x, y)
#define amax(x, y) x = max(x, y)
#define gcd(x, y) __gcd(x, y)
#ifdef NO_FILE
#define file(x) (void)0
#else
#define file(x) auto _ = freopen(x ".in", "r", stdin); \
                     _ = freopen(x ".out", "w", stdout); \
                (void)_;
#endif



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("travel");

    int c1, c2;
    string s1, s2;

    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 != c2) {
        cout << "0000\n";
        cout << flush;
        return 0;
    }
    if (s1[0] != s2[0] || s1[1] != s2[1]) {
        cout << "1000\n";
        cout << flush;
        return 0;
    }
    if (!((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))) {
        cout << "1100\n";
        cout << flush;
        return 0;
    }
    if ((s1[2] - s2[2]) > 1) {
        cout << "1110\n";
        cout << flush;
        return 0;
    }
    cout << "1111\n";
    cout << flush;
    return 0;
}
