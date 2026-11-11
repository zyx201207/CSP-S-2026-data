#include <bits/stdc++.h>
using namespace std;

#define pdb(expr) (cout << #expr ": " << (expr) << "\n")
#define redirect(file) freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
constexpr char BInf = 0x3F;
constexpr int Inf = 0x3F3F3F3F;
using ll = long long;
using ull= unsigned long long;

int n, m;
pair<int, int> a[200001];

bool c(pair<int, int> a, pair<int, int> b) {return a.first > b.first;}

int co(int c) {
    int q = 0;
    while (c != 0) {
        if ((c & 1) == 1) q++;
        c >>= 1;
    }
    return q;
}

int main() {
    redirect("and")
    cin >> n >> m;
    int mxb = 0;
    for (int i = 1; i <= n; i++) {
        int q;
        cin >> q;
        int c = co(q);
        a[i] = {q, c};
        if (a[mxb].second < c)
            mxb = i;
    }
    sort(a + 1, a + n + 1, c);
    int r = 0xFFFFFFFF;
    for (int i = 1; i <= m; i++) {
        r &= a[i].first;
    }
    cout << r;
}
