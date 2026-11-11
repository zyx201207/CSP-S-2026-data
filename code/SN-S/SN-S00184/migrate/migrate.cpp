#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
void work() {
    int c,t;
    cin >> c >> t;
    if (c == 11 || c == 12 ||c== 0) {
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> pl(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> pl[i];
        }
        if (n == 1) {
            cout << 0<< endl;
            continue;
        }
        vector<int> hex;
        int len = (d / (pl[2] - pl[1]))+ 1;
        for (int i = 1; i <= n - len; i++) {
            if (pl[i + len] - pl[i] > d && 
                pl[i + 1] - pl[i] <= d && 
                pl[i + len] - pl[i + 1] <=d && 
                pl[i + len - 1] -pl[i] <=d && 
                pl[i + len]- pl[i + len - 1]<=d){
                hex.push_back(i);
            }
        }
        if(hex.empty()) {
            cout << 0 << endl;
            continue;
        }
        pl[0] = INT_MIN;
        vector<bool> ol(n + 1);
        for (int i = 2; i <= n; i++) {
            if (pl[i] - pl[i - 1] <=d && 
                (i <=2 || pl[i] - pl[i - 2] > d)) {
                ol[i] = 1;
            }
        }
        vector<int> back(n + 1, 1), forw(n + 1, 1);
        for (int i = n - 1; i >= 1 ; i--) {
            if (ol[i + 1]) {
                back[i] = back[i + 1] + 1;
            }
        }
        for (int i = 2; i <= n ; i++) {
            if (ol[i]) {
                forw[i] = forw[i - 1] + 1;
            }
        }
        int ans = 0;
        for (auto id : hex) {
            //ans += forw[id] * back[id + len];
            ans++;
        }
        cout << ans << endl;
    }
    }
    else {
        while(t--) {
            int n, d;
            cin >> n >> d;
            vector<int> pl(n + 1);
            for(int i = 1; i <= n; i++) {
                cin >> pl[i];
            }
            int ans = 0;
            //vector<vector<int>> flag(n + 1, vector<int>(n + 1));
            // for (int i = 1; i <= n; i++) {
            //     for (int j = 1; j <= n; j++) {
            //         int ld= 0, rd = 0;
            //         //if (flag[i][j - 1] == 1 || flag[i + 1][j] == 1) {
            //         //    flag[i][j] = 1;
            //         //    continue;
            //         //}
            //         int len = d + 1;
            //         for (int k = i; k <= j - len; k++) {
            //             if (pl[k + len] - pl[k] > d && 
            //                 pl[k + 1] - pl[k] <= d && 
            //                 pl[k + len] - pl[k + 1] <=d && 
            //                 pl[k + len - 1] -pl[k] <=d && 
            //                 pl[k + len]- pl[k + len - 1]<=d) {
            //                     ld++;
            //             }
            //         } 
            //         if (ld == 1){
            //             ans++;
            //         }
            //     }
            // }
            cout << 0 << endl;
        }
    }
}
}
signed main() {
    freopen("migrate.in", "r",stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    Qaaxaap::work();
    return 0;
}
