#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m, a[200005], nxt[200005], ans = (1ll << 50) - 1;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    nxt[0] = 1;
    for (ll i = 1; i <= n; i++){
        nxt[i] = i + 1;
        cin >> a[i];
    }
    for (ll j = 31; j >= 0; j--){
        ll cnt = 0;
        for (ll i = nxt[0]; i != n + 1; i = nxt[i]){
            if ((a[i] >> j) & 1){
                cnt++;
            }
        }
        if (cnt >= m){
            ll pre = 0;
            for (ll i = nxt[0]; i != n + 1; i = nxt[i]){
                if (((a[i] >> j) & 1) == 0){
                    nxt[pre] = nxt[i];
                }
                else{
                    pre = i;
                }
            }
        }
    }
    for (ll i = nxt[0]; i != n + 1; i = nxt[i]){
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
