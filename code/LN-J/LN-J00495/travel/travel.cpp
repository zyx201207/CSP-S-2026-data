#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

string a[2], b[2];

inline void solve(){
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    string ans = "0000";
    if(a[0] == b[0]){
        ans[0] = '1';
        if(a[1][0] == b[1][0] && a[1][1] == b[1][1]){
            ans[1] = '1'; 
            int ax = (a[1][2] - 'A' + 1);
            int ay = (ax <= 3 ? 0 : 1);
            int bx = (b[1][2] - 'A' + 1);
            int by = (bx <= 3 ? 0 : 1);
            if(ay == by){
                ans[2] = '1';
                if(ay == 1) ans[3] = '1';
                else if(abs(ax - bx) == 1) ans[3] = '1';
            }
        }
    }
    cout << ans << "\n";
    return ;
}
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    return 0;
}