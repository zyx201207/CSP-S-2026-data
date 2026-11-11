#include<bits/stdc++.h>
#define in inline 

using namespace std;
const int M = 305;
int c, t, n, d, x[M];

in bool check(int l, int r) {
    int cnt = 0, num = 0; // 连续两个 一个
    bool tag = false;
    int last = l;
    while(1) {
        if(!tag) {
            int pos1 = lower_bound(x + 1, x + n + 1, x[last]) - x + 1;
            int pos2 = upper_bound(x + 1, x + n + 1, x[last] + d) - x - 1;
            if(pos2 - pos1 + 1 >= 2) return false;
            else if(pos2 == pos1) num++, last = pos1;
            else if(pos2 - pos1 + 1 == 2) cnt++, last = pos1;
            if(pos1 <= r && pos2 >= r && cnt != 0 && num != 0) return true; 
        } else {
            int pos1 = lower_bound(x + 1, x + n + 1, x[last]) - x + 1;
            int pos2 = upper_bound(x + 1, x + n + 1, x[last + 1] + d) - x - 1;
            if(pos1 != pos2) return false;
            else last = pos1, cnt++;
            if(pos1 == r) return true;  
        }
        if(last > r) return false;
    }
}

/*in void solve() {
    int ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(i == j) continue;
            if(check(i, j)) {
                ans++;
                
            }
        }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) x[i] = 0;
}*/

namespace force {
    in void solve() {
        int ans = 0, mn[M][M], way[M][M], n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        memset(mn, 0x3f, sizeof mn);
        memset(way, 0, sizeof way);
        for(int s = 0; s < (1 << n); s++) {
            int l = n, r = 0, len = 0;
            for(int i = 1; i <= n; i++) {
                if((s & (1 << (i - 1)))) l = min(i, l), r = max(r, i), len++;
            } int last = l; bool flag = 1;
            for(int i = l; i <= r; i++) {
                if(i == l) continue;
                if((s & (1 << (i - 1)))) {
                    if(x[i] - x[last] <= d) last = i;
                    else { flag = false; break; }  
                }
            }
            if(flag) {
                if(len < mn[l][r]) mn[l][r] = len, way[l][r] = 1;
                else if(len == mn[l][r]) way[l][r]++;
            }
        }
        for(int l = 1; l <= n; l++) {
            x[l] = 0;
            for(int r = l; r <= n; r++) {
                if(way[l][r] == 2) {
                    ans++;
                    //cout << l << " " << r << " " << ans << '\n';
                }
            }
        } cout << ans << '\n';
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t--) force::solve();
    return 0;
}