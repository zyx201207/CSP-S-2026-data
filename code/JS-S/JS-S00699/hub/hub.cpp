#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int C, T;
int n, k;
vector<int> g[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> C >> T;
    while(T--)
    {
        cin >> n >> k;
        for(int i = 1, u, v; i < n; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << g[1][1] << '\n';
    }
    return 0;
}
