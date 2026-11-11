#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
vector<ll> a;
ll ans = 0;
ll sm = 0;
deque<ll> dq;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    a.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (ll r = 1, l = 1; r <= n; r++)
    {
        while (dq.size() && a[dq.back()] <= a[r]) dq.pop_back();
        dq.push_back(r);
        sm += a[r];
        while (dq.size() && __int128(r - l + 1) * a[dq.front()] > m + sm)
        {
            sm -= a[l++];
            while (dq.size() && dq.front() < l) dq.pop_front();
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
/*
114514
1919810
917813
350234
关注 luogu clx201022 552688 喵，关注 clx201022 谢谢喵
合成大水晶？！
无敌？！
合成完可以领水晶之心吗（x）
*/