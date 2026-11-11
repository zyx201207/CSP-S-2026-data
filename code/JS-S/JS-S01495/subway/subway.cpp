#include <iostream>
#include <vector>
using namespace std;
int t, n, m, d, q, num, ans, x, y;
int w[500001];
bool bl[501];
vector<int> s[501], p[501], h[501];
int dfs(int a, int c, int o)
{
    for (int i = 1;i <= s[a].size();i++)
    {
        if (s[a][i] == c)
        {
            ans = min(ans, num);
            return 0;
        }
    }
    for (int i = 1;i <= s[a].size();i++)
    {
        if (!bl[s[a][i]])
        {
            num += p[a][i] + p[a][o];
            bl[w[s[a][i]]] = 1;
            dfs(s[a][i], c, h[a][o]);
            num -= p[a][i] * 2;
            bl[w[s[a][i]]] = 0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> t >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++)
    {
        s[i].push_back(0);
        int k, a, ts;
        cin >> k;
        for (int j = 1;j <= k * 2;j++)
        {
            cin >> a;
            s[i].push_back(a);
            cin >> ts;
            p[i].push_back(ts);
        }
    }
    for (int j = 1;j <= q;j++)
    {
        cin >> x >> y;
        for (int i = 1;i <= s[x].size();i++)
        {
            if (s[x][i] == y)
            {
                cout << w[x] + w[y];
                continue;
            }
        }
        int num = 0, ans = 0x3f;
        for (int i = 1;i <= s[x].size();i++)
        {
            dfs(x, y, h[x][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
