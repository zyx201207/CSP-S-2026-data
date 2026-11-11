#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
ll n;
ll ans;
string s;
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline ll solve(string s,string t)
{
    ll ans = 0;
    for(ll i = 0;i < (ll)(s.size());++i)
        ans += (s[i] != t[i]);
    return ans;
}
int main()
{
    openfile("string");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(ll i = 1;i <= n;++i)
    {
        ll x = 0;
        char c;
        cin >> x >> c;
        s += string(x,c);
    }
    string t = s;
    reverse(t.begin(),t.end());
    string pres = s.substr(0,(ll)(s.size()) >> 1);
    string pret = t.substr(0,(ll)(t.size()) >> 1);
    string sufs = s.substr((ll)(s.size()) / 2 + (s.size() & 1));
    string suft = t.substr((ll)(t.size()) / 2 + (s.size() & 1));
    ans = min(solve(pres,pret),solve(suft,sufs));
    cout << ans;
    return 0;
}
