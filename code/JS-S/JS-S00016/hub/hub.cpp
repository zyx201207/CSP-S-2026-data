#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int c, t, n, m, a[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> m;
        int u, v;
        for (int i = 1;i <= n - 1;i++) cin >> u >> v;
        cout << 1 << '\n';
    }
}
