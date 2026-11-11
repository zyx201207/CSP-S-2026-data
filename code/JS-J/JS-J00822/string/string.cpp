#include <bits/stdc++.h>
using namespace std;

#define pdb(expr) (cout << #expr ": " << (expr) << "\n")
#define redirect(file) freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
constexpr char BInf = 0x3F;
constexpr int Inf = 0x3F3F3F3F;
using ll = long long;
using ull= unsigned long long;
int n;
ll cha[200005]; // cha[i] == ln#i 's [~, end) pos
char ch[200005];

int main() {
    redirect("string")
    cin >> n;
    cha[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> cha[i] >> ch[i];
    }
    ll l = 1, r = cha[n] - 1, a = 1, sl = 1, sr = n;
    while (sl <= sr) {
        if (ch[sl] != ch[sr]) a++;
        // printf("%d %d %d %d %c %c\n", l, r, sl, sr, ch[sl], ch[sr]);
        l++, r--;
        if (l == cha[sl]) {sl++; l = 0;}
        if (r == 0) {sr--; r = cha[sr];};
    }
    cout << a;
}
