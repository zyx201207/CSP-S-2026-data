#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
vector<ll> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    a.resize(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll ans = -1e9;
    for(int i = n; i >= 1; i --){
        ll now = m;
        ll cnt = 1;
        for(int  j = i - 1; j >= 1; j --){
            if(now - (a[i] - a[j]) < 0) break;
            now -= (a[i] - a[j]);
            cnt ++;
        }
        ans = max(ans, cnt);
        if(ans >= i) break;
    }
    cout << ans << endl;
    return 0;
}

