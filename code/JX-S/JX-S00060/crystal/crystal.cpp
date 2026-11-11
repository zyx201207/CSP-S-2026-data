#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> v;
bool check(ll mid) {
    // ll t = m;
    // for(ll i = 1; i <= n; i++) {
    //     if(mid < v[i]) break;
    //     t -= (mid - v[i]);
    // }
    // return t >= 0;
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(mid < v[i]) break;
        cnt += mid - v[i];
    }
    return cnt <= m;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    v.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool flag = true, flag1 = true;
    for(ll i = 0; i < n; i++) {
        if(v[i] != i+1) {
            flag = false;
            break;
        }
    }
    ll c = v[1]-v[0];
    for(ll i = 0; i < n; i++) {
        if(i >= 1 && v[i]-v[i-1] != c) {
            flag1 = false;
            break;
        }
    }
    if(flag) {
        cout << (int)sqrt(m*2)+1;
    } else if(flag1) {
        ll ans = -1;
        for(ll i = 1; i < n; i++) {
            if((v[i]-v[0])*(i+1)/2 <= m) {
                ans = i;
            } else {
                break;
            }
        }
        cout << ans+1;
    } else {
        ll ma = v[n-1], mi = v[0];
        ll l = mi, r = ma+m;
        while(l + 1 < r) {
            ll mid = l+(r-l)/2;
            if(check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            if(v[i] > l) break;
            if(m - (l - v[i]) < 0) {
                break;
            }
            m -= (l - v[i]);
            ans++;
        }
        cout << ans;
    }
    return 0;
}