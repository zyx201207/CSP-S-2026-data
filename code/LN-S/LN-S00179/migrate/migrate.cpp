#include <bits/stdc++.h>
using namespace std;

template <typename T> bool ckmx(T &x, T y){return (x < y) ? (x = y, 1) : 0;}
template <typename T> bool ckmn(T &x, T y){return (x > y) ? (x = y, 1) : 0;}
typedef long long ll;

const int N = 2e6 + 5;

int n;
ll d, x[N];

int l[N], r[N], lc[N], rc[N], lv[N], rv[N];

void clear(){

}
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1, pl = 1, pr = 1; i <= n; i++){
        while(x[i] - x[pl] > d) pl++;
        while(x[pr] - x[i] <= d && pr <= n) pr++;
        l[i] = pl, r[i] = pr - 1;
    }
    for(int i = 1; i <= n; i++) lc[i] = rc[i] = lv[i] = rv[i] = 0;
    for(int i = 1; i <= n; i++){
        lc[i]++;
        if(r[i] != i)
            lc[r[i]]++;
        if(r[l[i]] == i)
            lc[i] += lc[l[i]] - 1;
    }
    for(int i = n; i >= 1; i--){
        rc[i]++;
        if(l[i] != i)
            rc[l[i]]++;
        if(l[r[i]] == i)
            rc[i] += rc[r[i]] - 1;
    }
    for(int i = 1; i <= n; i++){
        if(l[i] != i) rv[l[i]]++;
        if(r[i] != i) lv[r[i]]++;
    }
    // cerr << "l:";for(int i = 1; i <= n; i++) cerr << l[i] << " \n"[i == n];
    // cerr << "r:";for(int i = 1; i <= n; i++) cerr << r[i] << " \n"[i == n];
    // cerr << "lc:";for(int i = 1; i <= n; i++) cerr << lc[i] << " \n"[i == n];
    // cerr << "rc:";for(int i = 1; i <= n; i++) cerr << rc[i] << " \n"[i == n];
    ll ans = 0;
    for(int i = 2; i < n - 1; i++){
        if(r[i] == i + 1) continue;
        ll pl = lv[i + 1];
        if(l[i] != i && r[l[i]] == i + 1)
            pl += lc[l[i]] - 1;
        ll pr = rv[i];
        if(r[i + 1] != i + 1 && l[r[i + 1]] == i)
            pr += rc[r[i + 1]] - 1;
        ans += pl * pr;
        // cerr << pl * pr << ' ';
    }
    // cerr << '\n';
    cout << ans << '\n';
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(0);
    int c, T = 1;
    cin >> c >> T;
    while(T--){
        solve();
    }
    return 0;
}