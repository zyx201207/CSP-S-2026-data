#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct node{
    ll a, pos;
    char c;
};
vector<node> a;
vector<ll> m;
ll n, l, ans;
char get(ll x){
    ll l = 0, r = a.size() - 1;
    char rt;
    while (l <= r){
        ll mid = (l + r) / 2;
        if (a[mid].pos <= x){
            rt = a[mid].c;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return rt;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++){
        node x;
        cin >> x.a >> x.c;
        if (a.empty()) x.pos = 1;
        else x.pos = a[a.size() - 1].pos + a[a.size() - 1].a;
        l += x.a;
        if ((!a.empty()) && a[a.size() - 1].c == x.c){
            a[a.size() - 1].a += x.a;
        }
        else{
            a.push_back(x);
        }
    }
    m.push_back((l + 1) / 2);
    m.push_back(1);
    for (auto i: a){
        m.push_back(min(i.pos, l - i.pos + 1));
        m.push_back(min(i.pos + i.a - 1, l - i.pos - i.a + 1 + 1));
    }
    sort(m.begin(), m.end());
    ll lst = 0;
    for (auto i: m){
        if (i != lst){
            if (get(l - i + 1) != get(i)) ans += i - lst;
            lst = i;
        }
    }
    cout << ans;
    return 0;
}
