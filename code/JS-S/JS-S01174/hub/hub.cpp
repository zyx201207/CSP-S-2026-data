#include <bits/stdc++.h>
const int N = 2e6 + 10;
using namespace std;
vector<int>edge[N];
int n, k;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, T; cin >> c >> T;
    while (T--)
    {
        cin >> n >> k;
        for (auto &x : edge) x.clear();
        for (int i = 1; i < n; i++)
        {
            int u, v; cin >> u >> v;
            edge[u].push_back(v); edge[v].push_back(u);
        }
        // if (c == 13 || c == 14)
        // {
            if (k == n) cout << "0\n";
            else if (k >= n / 2) cout << "1\n";
            else {
                int len = n / 2 + 1;
                int a = k / 2 - 1, b = (k + 1) / 2 - 1;
                len -= (a + b);
                int tmp = (len + 2) / 3;
                len = n / 2 + 1;
                int ans = min(tmp, (len - k + 2) / 2);
                cout << ans << "\n";
            }
            continue;
        // }
    }
    return 0;
}
