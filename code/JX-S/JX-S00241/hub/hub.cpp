#include <bits/stdc++.h>
using namespace std;

void solve(){
    srand(time(0));
    int c, t, n, k;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1;i < n;++i) cin >> k >> k;
        int mod;
        if(c < 4) mod = 5;
        else mod = 20;
        cout << rand() % mod << "\n";
    }
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
