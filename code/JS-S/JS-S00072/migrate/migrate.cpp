#include<bits//stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
int x[N];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;
    cin >> c >> _;
    while(_--)
    {
        int n,d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if(c == 11 && c == 12)
        {
            int y = d / (x[2] - x[1]);
            if(y <= 1) cout << 0 << endl;
            else if(y >= n) cout << 0 << endl;
            else
            {
                y = y * 2 - 1;
                cout << n - y << endl;
            }
        }
        if(c == 0 || c == 1 || c == 2)
        {
            int dp[15][15][15];
            for(int i = 1;i <= n;i++)
                    dp[i][i][0] = 1;
            for(int u = 1;u <= n;u++)
                for(int v = u + 2;v <= n;v++)
                    if(x[v] - x[u] > d)
                        for(int i = 0;i <= n;i++)
                            for(int j = u;j <= v;j++)
                                if(x[v] - x[j] <= d)
                                    dp[u][v][i + 1] = dp[u][j][i] + 1;
            int ans = 0;
            for(int u = 1;u <= n;u++)
                for(int v = u + 2;v <= n;v++)
                    for(int i = 1;i <= n;i++)
                        if(dp[u][v][i] != 0 && dp[u][v][i] != 2) break;
                        else if(dp[u][v][i] == 2)ans++;
            cout << ans << endl;
        }
    }
    return 0;
}
