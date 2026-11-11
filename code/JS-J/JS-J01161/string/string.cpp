#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int l[200001];
char c[200001];

int len(pair<int, int> x) {
    return x.second - x.first + 1;
}

void fresh(pair<int, int>& lp, pair<int, int>& rp, int& lc, int& rc) {
    if (len(lp) <= 0) {
        lp.first = lp.second + 1;
        lp.second += l[++lc];
    }
    if (len(rp) <= 0) {
        rp.second = rp.first - 1;
        rp.first -= l[--rc];
    }
}

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long e = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> c[i];
        e += l[i];
    }
    pair<int, int> lp, rp;
    int lc = 1, rc = n;
    lp = {1, l[lc]};
    rp = {e - l[rc] + 1, e};
    long long ans = 0;
    for (; ;) {
        if (lp.second < rp.first) {
            int cut = min(len(lp), len(rp));
            if (c[lc] != c[rc]) {
                ans += cut;
            }
            lp.first += cut;
            rp.second -= cut;
            fresh(lp, rp, lc, rc);
        }
        else {
            break;
        }
    }
    cout << ans;
}
