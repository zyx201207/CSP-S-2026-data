#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N], ans, m, k;
vector <int> G[N];

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        } int m = (n + 1) / 2;
            if(k == 1) cout << (m + 1) / 2;
            else if(k <= m - 1) cout << (m - k + 2) / 4 + 1;
            else if(k < n) cout << 1;
            else cout << 0;
            cout << endl;
    }
    return 0;
}
