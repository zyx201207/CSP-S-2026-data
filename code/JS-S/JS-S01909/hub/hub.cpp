#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
ll c, t, n, k, u, v;
vector <ll> e[N];
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout << k - 1 << '\n';
    }
    return 0;
}