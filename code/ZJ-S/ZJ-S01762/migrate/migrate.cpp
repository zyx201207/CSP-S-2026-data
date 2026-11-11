#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, d, pos[N], ans, dis[N], cnt[N];
void calc(int s){
    dis[s] = 0, cnt[s] = 1;
    for(int t = s + 1, sum = 1, i = s, j = s; t <= n; t++){
        dis[t] = cnt[t] = 0;
        while(pos[t] - pos[i] > d) sum -= cnt[i], i++;
        while(j < (i - 1)) j++, sum += cnt[j];
        while(j < (t - 1) && dis[j + 1] == dis[i]) j++, sum += cnt[j];
        cnt[t] = sum, dis[t] = dis[i] + 1;
        if(cnt[t] == 2) ans++;
        // cout << s << " " << t << " " << i << " " << j << " " << dis[t] << " " << cnt[t] << endl;
    }
}
void solve(){
    cin >> n >> d, ans = 0;
    for(int i = 1; i <= n; i++) cin >> pos[i];
    if(n > 5000) return cout << 0 << endl, void();
    for(int i = 1; i <= n; i++) calc(i);
    cout << ans << endl;
}
signed main(){
    // freopen("ex_migrate/migrate3.in", "r", stdin);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
