#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 0x3f;
#define mst(x, y) memset(x, y, sizeof(x))
#define endl '\n'
const int N = 2e6+6;
ll a[N], r, n, d;
void cnt(int x, int y){
    cout << x << " " << y << ",";
    if(x == y) r++;
    else{
        for(int i = x+1; ; i++){
            if(a[i]-a[x] > d){
                continue;
            }else{
                cnt(i, y);
            }
        }
    }
}
signed mian(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            r = 0;
            cnt(i, j);
            if(r == 2) ans++;
        }
    }
    cout << ans;
    return 0;
}
signed main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        mian();
    }
    return 0;
}
