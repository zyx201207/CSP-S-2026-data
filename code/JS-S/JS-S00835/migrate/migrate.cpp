#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N =4e4 + 7;
int c, t;
ll n, d, x[N], num, ans;
bool edges[N][N], vis[N];//wo bu hui lianshi qianxiangxing(I don't have Chinese IME)
int bfs(int a, int b)
{
    memset(vis, false, sizeof(vis));
    queue<pii> q = {};
    q.push({a, 0});
    bool found = false;
    int cnt = 0;
    int min_len = INT_MAX;
    while (!q.empty())
    {
        pii now = q.front();
        if (vis[now.first])
        {
            q.pop();
            continue;
        }
        vis[now.first] = true;
        q.pop();
        if (min_len < now.second)
        {
            break;
        }
        if (now.first == b)
        {
            found = true;
            min_len = min(min_len, now.second);
            if (min_len == now.second)
            {
                cnt ++;
            }
            
        }
        if (!found)
        {
            for (int i = 1; i <= n; i ++)
            {
                if (edges[now.first][i])
                {
                    q.push({i, now.second + 1});
                }
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> t;
    if (n <= 4e4+7)
    {
        while(t --)
        {
            cin >> n >> d;
            for (int i = 1; i <= n; i ++)
            {
                cin >> x[i];
            }
            num = 0;
            for (int i = 1; i <= n; i ++)
            {
                for (int j = i + 1; j <= n ; j ++)
                {
                    if (abs(x[j] - x[i]) <= d)
                    {
                        edges[i][j] = true;
                        edges[j][i] = true;
                    }
                    else
                    {
                        edges[i][j] = false;
                        edges[j][i] = false;
                    }
                }
            }
            for (int i = 1; i <= n - 1; i ++)
            {
                for (int j = i + 1; j <= n; j ++)
                {
                    if (bfs(i,j) == 2)
                    {
                        ans ++;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    

    return 0;
}