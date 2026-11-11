#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 5e5 + 5;
int w[M], k[N];
int a[N][M];
ll t[N][M];
vector <int> b[M], G[N];
unordered_map <pair<int, int>, int> mp;
int main()
{
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            b[a[i][j]].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(auto j : G[i])
        {
            for(auto k : G[i])
            {
                if(j == k)
                {
                    continue;
                    
                }
            }
        }
    }
    return 0;
}