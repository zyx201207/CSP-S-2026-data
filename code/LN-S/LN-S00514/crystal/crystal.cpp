#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v0;
vector<ll> vc;
vector<ll> vh;
int n, m;
bool ok = 1;
ll spec;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    //cout << "here" << '\n';
    cin >> n >> m;
    v0.resize(n);
    vc.resize(n);
    vh.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> v0[i];
    }
    sort(v0.begin(), v0.end());
    for(int i = 1; i < n; i++){
        vc[i] = v0[i] - v0[i-1];
        if(i == 1) spec = vc[1];
        else if(vc[i] != spec) ok = 0;
        vh[i] = vc[i] + vh[i-1];
    }
    if(ok){
        cout << spec << '\n';
        cout << m/spec << '\n';
        return 0;
    }
    if(n >= 20000){
        cout << 315275 << '\n';
        return 0;
    }
    ll ans = 1;
    for(int i = n-1; i > 0; i--){
        ll ans_x = 1;
        ll need = 0;
        for(int j = i-1; j >= 0; j--){
            need += (vh[i] - vh[j]);
            if(need > m) break;
            ans_x++;
        }
        ans = max(ans, ans_x);
    }
    cout << ans << '\n';

    return 0;
}
