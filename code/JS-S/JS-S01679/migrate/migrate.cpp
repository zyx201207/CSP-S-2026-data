#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
int c, T, n, ans;
LL d;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T--)
    {
        ans = 0;
        cin >> n >> d;
        LL len[n], x1, x2, sum = 0;
        LL to[n + 1][n + 1];
        int cnt[n + 1][n + 1];
        for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++)
                    to[i][j] = INF;
        cin >> x2;
        for(int i = 1; i < n; i++)
        {
            x1 = x2;
            cin >> x2;
            len[i] = x2 - x1;
        }
        for(int i = n - 1, r = n; i >= 1; i--)
        {
            sum += len[i];
            while(sum > d && r > i)
                sum -= len[--r];
            for(int j = i + 1; j <= r; j++)
                to[i][j] = cnt[i][j] = 1;
            for(int j = i + 2; j <= n; j++)
            {
                if(to[i][j] == 1)
                    continue;
                LL len = to[i][j];
                cnt[i][j] = 1;
                for(int k = i + 1; k <= j; k++)
                {
                    if(to[k][j] == INF || to[i][k] != 1)
                        break;
                    if(to[i][k] + to[k][j] < len)
                        len = to[i][k] + to[k][j], cnt[i][j] = cnt[k][j];
                    else if(to[i][k] + to[k][j] == len)
                        cnt[i][j] += cnt[k][j];
                }
                to[i][j] = len;
                if(cnt[i][j] == 2)
                    ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
