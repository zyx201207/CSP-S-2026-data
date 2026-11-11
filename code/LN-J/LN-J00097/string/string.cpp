#include <bits/stdc++.h>
using namespace std;
using PIC = pair<int, char>;
using ll = long long;

int n, t;
ll ans;
char c;
vector<PIC> v(n);
void o_x(const auto &vx){
    for(auto x : vx) cout << x.first << ' ' << x.second << '\n';
    return;
}
ll solve(auto &vx){
    ll l = 0;
    ll r = n-1;
    while(l < r){
        int t1 = vx[l].first;
        int t2 = vx[r].first;
        char c1 = vx[l].second;
        char c2 = vx[r].second;
        //cout << t1 << ' ' << t2 << ' ' << c1 << ' ' << c2 << '\n';
        if(t1 > t2){
            if(c1 != c2) ans += t2;
            vx[l].first -= t2;
            r-= 1;
        }
        else if(t1 == t2){
            if(c1 != c2) ans += t2;
            l += 1;
            r -= 1;
        }
        else{
            if(c1 != c2) ans += t1;
            vx[r].first -= t1;
            l += 1;
        }
    }
    return ans;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.reserve(n);
    for(int i = 0; i < n; i++){
        cin >> t >> c;
        v.emplace_back(t,c);
    }
    //o_x(v);
    solve(v);
    cout << ans;
    return 0;
}
