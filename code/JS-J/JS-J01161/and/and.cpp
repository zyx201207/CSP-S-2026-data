#include <iostream>
#include <unordered_set>
using namespace std;

#define int uint64_t

int raw[200001];

int getbit(int x, int index) {//index from low to high is 0-63
    return (x >> index) & 1;
}

unordered_set<int> c;

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        raw[i] = x;
        c.insert(i);
    }
    for (int32_t i = 63; i >= 0; i--) {
        int cnt = 0;
        for (int x : c) {
            if (getbit(raw[x], i)) cnt++;
        }
        if (cnt >= m) {
            for (auto p = c.begin(); p != c.end(); ) {
                if (getbit(raw[*p], i) == 0) {
                    p = c.erase(p);
                }
                else p++;
            }
        }
    }
    int cnt = 0;
    int ans = ~0ull;
    for (int x : c) {
        ans &= raw[x];
        cnt++;
        if (cnt == m) break;
    }
    cout << ans;
}
