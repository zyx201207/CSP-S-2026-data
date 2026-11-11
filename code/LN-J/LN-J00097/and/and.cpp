#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void o_x(const auto &v0){
    for(auto x0 : v0){
        cout << x0 << ' ';
    }
    return;
}

void fen(ll x0, vector<char> &v0){
    for(int i = 30; i >= 0; i--){
        v0[i] = '0';
        ll m = (1 << i);
        if(x0 & m){
            v0[i] = '1';
            x0 &= (m -1);
        }
        //cout << v0[i] << ' ';
    }
}

int n, m;
int main(){
    freopen("and.in", "r", stdin);
    freopen("add.out", "w", stdout);
    cin >> n >> m;
    vector<ll> a;
    a.reserve(n);
    vector<char> v[n];
    vector<bool> jug(n,0);
    for(int i = 0; i < n; i++){
        v[i].resize(30);
        ll x = 0;
        cin >> x;
        a.emplace_back(x);
        fen(x,v[i]);
        jug[i] = 1;
        //o_x(v[i]);
    }
    //o_x(a);
    int rest = n;
    for(int i = 30; i >= 0; i--){
        int t = 0;
        if(rest <= m) break;
        for(int j = 0; j < n; j++){
            if(jug[j] && v[j][i] == '1') t++;
        }
        //cout << i << ' ' << t << '\n';
        if(t >= m){
            for(int j = 0; j < n; j++){
                if(jug[j] && v[j][i] == '0'){
                    jug[j] = 0;
                    rest--;
                    if(rest == 2) break;
                }
            }

        }
    }
    //o_x(jug);
    ll p = 0;
    ll ans = - 1;
    int now_x = 0;
    for(int i = 0; i < n; i++){
        if(now_x == m) break;
        if(jug[i] == 1){
            p = a[i];
            ans &= p;
            now_x++;
        }
    }
    cout << ans;
    return 0;
}
