#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int> > g;
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int u, v;
        for (int i = 1; i <= n; i++)
        {
            cin >> u >> v;
            g.push_back({u, v});
            g.push_back({v, u});
        }
        cout << k - t << endl;
    }
    return 0;
}
