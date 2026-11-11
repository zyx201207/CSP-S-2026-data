#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a);i <= (b);i++)
typedef long long ll;
typedef pair<int, int> pii;
const int Max = 2e6+5;
int n;ll d, a[Max];
bool check(int l, int r)
{
    if(r-l+1 < 4)return 0;
    vector<int> cnt(r-l+6, 0), dis(r-l+6, 1e8);
    vector<bool> vis(r-l+6, 0);
    queue<int> q;q.push(l);dis[0] = 0;cnt[0] = 1;
    while(!q.empty())
    {
        int x = q.front();q.pop();
        rep(i, x+1, r)
        {
            if(a[i]-a[x] > d)break;
            if(dis[x-l] >= dis[i-l])continue;
            if(!vis[i-l])vis[i-l] = 1, q.push(i), dis[i-l] = dis[x-l]+1;
            cnt[i-l] += cnt[x-l];
        }
    }
    return (cnt[r-l] == 2);
}
void solve()
{
    //%%%CT_1024
    cin >> n >> d;
    rep(i, 1, n)cin >> a[i];
    if(n <= 1000)
    {
        ll ans = 0;
        rep(i, 1, n)rep(j, i+1, n)ans += check(i, j);
        cout << ans << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c, _;cin >> c >> _;
    while(_--)solve();
    return 0;
}
