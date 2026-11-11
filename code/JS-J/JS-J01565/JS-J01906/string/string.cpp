#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 2e5 + 10;
ll n;
struct node{
    ll x, l, r;
    char c;
}a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll s = 0;
    for (ll i = 1; i <= n; ++ i){
        cin >> a[i].x >> a[i].c;
        a[i].l = s + 1, a[i].r = s + a[i].x;
        s += a[i].x;
    }
    string str;
    str += ' ';
    for (ll i = 1; i <= n; ++ i){
        for (ll j = 1; j <= a[i].x; ++ j){
            str += a[i].c;
        }
    }
    ll mid = (s + 1) / 2, ans = 0;
    for (ll i = 1; i <= mid; ++ i){
        if (str[i] != str[s - i + 1]) ans ++;
    }    
    cout << ans << endl;
    return 0;
}
//