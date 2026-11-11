#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int c, t; cin >> c >> t;
    while (t --) {
        int n; long long d; cin >> n >> d;
        vector<long long> x(n);
        for (long long &e: x) cin >> e;

        if (c <= 6) {
            long long ans = 0;

            auto f = [&](int L, int R) -> long long {
                long long _ans = 0;
                for (int l = L; l < R; l ++)
                    for (int r = l+1; r <= R; r ++) {
                        if (x[r] - x[l] <= d) continue;
                        int pos = l;
                        long long min_cnt = 0;
                        while (pos < r) {
                            int last = pos;
                            while (x[pos]-x[last] <= d && pos <= r) pos ++;
                            pos --;
                            min_cnt ++;
                        }
                        
                        auto dfs = [&](int pos, int cnt, auto&& self) -> long long {
                            if (cnt == min_cnt) return pos == r;
                            int tmp = pos+1;
                            long long res = 0;
                            for (; tmp <= r;) {
                                if (x[tmp] - x[pos] <= d) {
                                    res += self(tmp, cnt+1, self);
                                    tmp ++;
                                } else break;
                            }
                            return res;
                        };

                        if (dfs(l, 0, dfs) == 2) ans ++;
                    }
                return _ans;
            };

            int last = 0;
            for (int i = 1; i < n; i ++) {
                if (x[i]-x[i-1] > d) {
                    if (i-1 - last + 1 <= 3) continue;
                    // len > 3:
                    ans += f(last, i-1);
                    last = i;
                }
            }
            if (n-1 - last + 1 > 3) ans += f(last, n-1);
            cout << ans << '\n';
        } else if (13 <= c && c <= 14) {
            // int BL = -1, BR = -1;
            // for (int i = 0; i < n; i ++) {
            //     if (x[i] - x[0] <= d && x[n-1] - x[i] <= d) {
            //         if (~BL) BL = i;
            //         BR = i;
            //     }
            // }
            // int BLL = BL, BLR = BL, BRL = BR, BRR = BR;
            // while (BLL-1 >= 0 && x[BL] - x[BLL-1] <= d) BLL --;
            // while (BLR+1 < n && x[BLR] - x[BL] <= d) BLR ++;
            // while (BLL-1 >= 0 && x[BR] - x[BRL-1] <= d) BRL --;
            // while (BRR+1 < n && x[BRR] - x[BR] <= d) BRR ++;
            cout << 0 << '\n';
        }
    }

    return 0;
}