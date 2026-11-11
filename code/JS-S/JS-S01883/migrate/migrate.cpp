#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 2e6 + 1;

ll c, t;
ll n, d;
ll x[maxn];
ll cnt, minnlen;
ll ans;
void dfs(ll cur, ll goal, ll len){
    if(cur == goal){
        if(minnlen > len){
            minnlen = len;
            cnt = 1;
        }else if(minnlen == len){
            cnt++;
        }
        return ;
    }
    for(ll chi = cur + 1; chi <= goal; chi++){
        if(x[chi] - x[cur] <= d){
            dfs(chi, goal, len + 1);
        }
    }
}
void solve(ll testnum, ll casenum){
    cin >> n >> d;
    for(ll i = 1; i <= n; i++){
        cin >> x[i];
    }
    ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = i + 1; j <= n; j++){
            cnt = 0;
            minnlen = 0x3f3f3f3f3f3f3f3f;
            dfs(i, j, 0);
            if(cnt == 2){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;
    for(ll casei = 1; casei <= t; casei++){
        solve(c, casei);
    }
    cout << flush;
    return 0;
}
