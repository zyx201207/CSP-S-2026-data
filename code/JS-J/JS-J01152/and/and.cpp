#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll M = 32;
ll n;
ll m;
ll ans;
ll a[N];
bool flag;
vector <ll> cnd;
vector <ll> pos[M];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
int main()
{
    openfile("and");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;++i)
    {
        cin >> a[i];
        for(ll j = 0;j < M;++j)
            if((a[i] >> j) & 1)
                pos[j].push_back(i);
    }
    for(ll k = M - 1;k >= 0;--k)
    {
        if(pos[k].size() < m)
            continue;
        if(!flag)
        {
            cnd = pos[k];
            ans += (1ll << k);
            flag = true;
            continue;
        }
        vector <ll> nxt;
        for(auto i : cnd)
            if(binary_search(pos[k].begin(),pos[k].end(),i))
                nxt.push_back(i);
        if(nxt.size() < m)
            break;
        ans += (1ll << k);
        cnd = nxt;
    }
    cout << ans;
    return 0;
}
