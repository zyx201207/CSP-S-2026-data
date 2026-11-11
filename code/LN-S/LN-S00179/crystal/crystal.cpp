#include <bits/stdc++.h>
using namespace std;

template <typename T> bool ckmx(T &x, T y){return (x < y) ? (x = y, 1) : 0;}
template <typename T> bool ckmn(T &x, T y){return (x > y) ? (x = y, 1) : 0;}
typedef long long ll;

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    ll cost = 0;
    for(int l = 1, r = 1; r <= n; r++){
        cost += (r - l) * (a[r] - a[r - 1]);
        while(cost > m){
            cost -= a[r] - a[l];
            l++;
        }
        // if(r == n)
        //     cerr << l << ' ' << r << ' ' << cost << '\n';
        ckmx(ans, r - l + 1);
    }
    cout << ans << '\n';
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}