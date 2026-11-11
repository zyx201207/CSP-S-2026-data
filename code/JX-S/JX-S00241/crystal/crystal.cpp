#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
long long n, m, a[N], ans = 1, vis[205];
bool ok = 1, ok2 = 1;
set<int> s;
void solve(){
    cin >> n >> m;
    if(n == 1){
        cin >> m;
        cout << 1;
        return;
    }else if(n == 2){
        cin >> a[1] >> a[2];
        cout << ((abs(a[1] - a[2]) <= m) ? 2 : 1);
        return;
    }
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(i > 2 && ok && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) ok = 0;
        if(ok2 && (a[i] < -100 || a[i] > 100)) ok2 = 0;
    }
    if(ok2){
        for(int i = 1;i <= n;++i) ++vis[a[i] + 100], s.insert(a[i]);
        memset(a, 0, sizeof(a));
        int cnt = 0;
        for(auto it = s.begin();it != s.end();++it) a[++cnt] = *it;
        sort(a + 1, a + s.size() + 1);
        for(int i = 1;i <= s.size();++i){
            int s = m, cnt = vis[a[i] + 100];
            for(int j = i - 1;j && s;--j){
                int t = min(s / (a[i] - a[j]), vis[a[j] + 100]);
                s -= t * (a[i] - a[j]);
                cnt += t;
            }
            ans = max(ans, cnt);
        }
        cout << ans;
        return;
    }
    if(ok){
        cout << (int)((sqrtl((m << 3) / (a[n] - a[n - 1]) + 1) + 1) / 2);
        return;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;++i){
        int s = m, cnt = 1;
        for(int j = i - 1;j;--j){
            if(s >= a[i] - a[j]) s -= a[i] - a[j], ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
