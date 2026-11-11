#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+5;
const ll MINA = 1e12;
inline ll max(ll a, ll b) { return a > b ? a : b; }

ll n, m;
ll a[MAXN];
ll ans;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]); a[i] += MINA;
    }
    sort(a + 1, a + n + 1);
    for(ll i = 1, j = 1, cur = 0; i <= n; i++)
    {
        cur += (a[i] - a[i-1]) * (i - j);
        for(; cur > m; )
        {
            cur -= a[i] - a[j++];
        }
        // cerr << cur << ' ' << i << ' ' << j << endl;
        ans = max(ans, i - j + 1);
    }
    printf("%lld\n", ans);


    return 0;
}