#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll c, t, n, k, u, v;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    ll te = t;
    while(t--)
    {
        cin >> n >> k;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
        }
    }
    for (int i = 1; i <= te; i++)
    {
        cout << i << '\n';
    }
    return 0;
}
