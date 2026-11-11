#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct S{
    ll num;
    char c;
};
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<S> v(n+1);
    ll a;
    char c;
    for(int i = 1; i <= n; i++) {
        cin >> a >> c;
        v[i] = {a, c};
    }
    ll l = 1, r = n;
    ll ans = 0;
    while(l <= r) {
        if(v[l].c != v[r].c) {
            if(v[l].num < v[r].num) {
                ans += v[l].num;
                v[r].num -= v[l].num;
                l++;
            } else {
                ans += v[r].num;
                v[l].num -= v[r].num;
                r--;
            }
        } else {
            if(v[l].num < v[r].num) {
                v[r].num -= v[l].num;
                l++;
            } else {
                v[l].num -= v[r].num;
                r--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}