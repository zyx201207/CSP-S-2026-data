#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, T;
int n;
ll d;
const int MAXN = 2e6 + 10;
ll x[MAXN];
int fa[MAXN];
int dp[MAXN], f[MAXN];
ll solve()
{
    ll ans = 0;
    for(int st = 1; st <= n; ++st)
    {
        for(int i = st; i <= n; ++i) dp[i] = f[i] = 0;
        f[st] = 1;
        int j = st;
        for(int i = st + 1; i <= n; ++i)
        {
            while (x[i] - x[j] > d) ++j;
            fa[i] = j;
        }
        for(int i = st + 1; i <= n; ++i)
        {
            if (fa[i] == i) break;
            dp[i] = dp[fa[i]] + 1;
            for(int j = fa[i]; j < i && j <= fa[i] + 2; ++j)
            {
                if (dp[j] == dp[fa[i]]) f[i] += f[j];
            }
            if (f[i] >= 3) f[i] = 3;
            if (f[i] == 2) 
            {
                cout << st << ' ' << i << '\n';
            }
        }
    }
    return ans;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> T;
    while (T--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; ++i) cin >> x[i];
        cout << solve() << '\n';
    }
    return 0;
}