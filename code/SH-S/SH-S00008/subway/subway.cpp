#include<bits/stdc++.h>
using namespace std;

const int N = 505, M = 1e5 + 5, K = 1e3 + 5;
int C, n, m, d, q, w[N], k[N], a[N][K], t[N][K];
int dis[N];
vector<int> g[N];

int solve(int x, int y)
{

}

int main()
{
     freopen("subway.in", "r", stdin);
     freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            g[i].push_back(j);
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}
