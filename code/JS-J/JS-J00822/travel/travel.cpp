#include <bits/stdc++.h>
using namespace std;

#define pdb(expr) (cout << #expr ": " << (expr) << "\n")
#define redirect(file) freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
constexpr char BInf = 0x3F;
constexpr int Inf = 0x3F3F3F3F;
using ll = long long;
using ull= unsigned long long;

bool inabc(char c) {
    return c == 'A' || c == 'B' || c == 'C';
}

int main() {
    redirect("travel")
    int c1, s1, c2, s2; char a, b;
    cin >> c1 >> s1 >> a >> c2 >> s2 >> b;
    bool b1 = c1 == c2,
         b2 = s1 == s2,
         b3 = inabc(a) == inabc(b),
         b4 = abs(a - b) == 1;
    cout << (b1 ? "1" : "0");
    cout << ((b1 && b2) ? "1" : "0");
    cout << ((b1 && b2 && b3) ? "1" : "0");
    cout << ((b1 && b2 && b3 && b4) ? "1" : "0");
}
