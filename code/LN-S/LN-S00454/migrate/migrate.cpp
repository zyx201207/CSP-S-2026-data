

#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;
// migrate
const int mod = 1e9 + 7;
const int N = 2e6 + 5, M = 5e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
mt19937_64 rng(time(0));

int Case, n, k, a[N];
vector < pair<int, int> > p; 

int calc(int l, int r){
    int cnt = 1, now = 0, pre = 0;
    for(int i = l;i <= r; i++){
        int v = (pre == 0 ? 0 : a[i] - a[i - 1]);
        if(pre == 0) pre = i;
        if(now + v <= k) now += v;
        else cnt += 1, pre = i - 1, now = v;
    }
    return cnt;
}

inline void solve(){
    cin >> n >> k;
    for(int i = 1;i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int l = 1;l <= n; l++){
        for(int r = l + 1;r <= n; r++){
            if(a[r] - a[r - 1] > k) break;
            int cnt = 1, now = 0, pre = 0;
            for(int i = l;i <= r; i++){
                int v = (pre == 0 ? 0 : a[i] - a[i - 1]);
                if(pre == 0) pre = i;
                if(now + v <= k) now += v;
                else{
                    p.push_back({pre, i - 1});
                    cnt += 1, pre = i - 1, now = v;
                }
            }
            p.push_back({pre, r});
            int num = 0;
            for(int i = 0;i < cnt; i++){
                int now = i + 1 + calc(p[i].second - 1, r);
                if(now == cnt) num += 1;
                now = i + 1 + calc(p[i].second - 2, r);
                if(now == cnt) num += 1;
            }
            if(num == 1) ans += 1;
            p.clear();
        }
    }
    cout << ans << "\n";
    return ;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    cin >> Case >> tc;
    while(tc--) solve();
    
    return 0;
}

