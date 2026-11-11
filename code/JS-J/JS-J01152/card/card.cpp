#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
ll n;
ll m;
ll a[N];
ll cnt[N];
ll ans[N];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
int main()
{
    openfile("card");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;++i)
        cin >> a[i];
    for(ll i = 1;i <= n;++i)
    {
        vector <ll> cur;
        for(ll j = i;j <= n;++j)
        {
            if(cnt[a[j]])
            {
                vector <ll> nxt;
                for(auto x : cur)
                {
                    if(x == a[j])
                        break;
                    nxt.push_back(x);
                }
                nxt.push_back(a[j]);
                cur = nxt;
            }
            else
            {
                cur.push_back(a[j]);
                cnt[a[j]]++;
            }
        }
        for(auto x : cur)
        {
            ans[x]++;
            cnt[x]--;
        }
    }
    for(ll i = 1;i <= m;++i)
        cout << ans[i] << " ";
    return 0;
}
