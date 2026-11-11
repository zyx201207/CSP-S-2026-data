#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N];
ll dis[N], pre[N];
ll sum(int x, int y)
{
    return pre[y] - pre[x] - (x - 1) * (dis[y] - dis[x]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)
        dis[i] = dis[i - 1] + a[i] - a[i - 1];
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (dis[i] - dis[i - 1]) * (i - 1);
    int l = 1, r = 1;
    int ans = -1;
    while(l <= r &&  r <= n)
    {
        if(sum(l, r) <= m) ans = max(ans, r - l + 1);
        if(sum(l, r) <= m) r++;
        else if(sum(l, r) > m) l++;
    }
    cout << ans << endl;
    return 0;
}
//15:39 T1 seems to be solved
