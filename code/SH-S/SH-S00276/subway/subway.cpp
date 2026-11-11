#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int c, n, m, d, q;
int w[N];
struct P
{
    int k;
    vector<int> a;
    vector<int> t;
}xx[N];
int dfs(int src, int dst)
{
    // cout << "dfs(" << src << ", " << dst << ")" << '{' << endl;
    if (src == dst)
    {
        // cout << "src = dst" << endl;
        return 0;
    }
    int ret = 0x3f3f3f3f;
    for (int i = 1; i <= m; ++ i )
    {
        // cout << "i = " << i << endl;
        // for (int j = 1; j <= xx[i].k; ++ j )
        // {
        //     cout << xx[i].a[j] << ' ';
        // }
        // cout << endl;
        for (int j = 1; j <= xx[i].k; ++ j )
        {
            // cout << "j = " << j << endl;
            if (xx[i].a[j] == src)
            {
                int ans = xx[i].t[j];
                for (int k = j + 1; k <= xx[i].k; ++ k )
                {
                    // cout << "k = " << k << endl;
                    // cout << "from line " << i << " , " << j << " th, transfer to " << k << " th" << endl;
                    ans += xx[i].t[k];
                    // cout << "ans = " << ans <<endl;
                    int tmp = dfs(xx[i].a[k], dst);
                    // cout << "tmp = " << tmp << endl;
                    // cout << "dfs(xx[i].a[k], dst) = " << tmp << endl;
                    // cout << "ret = " << ret << endl;
                    ret = min(ret, ans + tmp);
                    // cout << " -> " << ret << endl;
                    // cout << "ans + tmp = " << ans + tmp << endl;
                    ans -= xx[i].t[k];

                    /*
                    ans += xx[i].t[k];
                    ret = min(ret, ans + dfs(xx[i].a[k], dst))
                    ans -= xx[i].t[k];
                    */
                }
            }
        }
    }
    // cout << "}" << endl;
    return ret;
}
int Query(int xx, int yy)
{
    return dfs(xx, yy) + w[xx] + w[yy]; 
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++ i )
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++ i )
    {
        cin >> xx[i].k;
        // cout << "-> " << xx[i].k << endl;
        xx[i].a.push_back(0);
        xx[i].t.push_back(0);
        for (int j = 1; j <= xx[i].k; ++ j )
        {
            int x, y;
            scanf("%d%d", &x, &y);
            // cout << "x = " << x << ", y = " << y << endl;
            xx[j].a.push_back(x);
            xx[j].t.push_back(y);
        }
        // for (int j = 1; j <= xx[i].k; ++ j )
        // {
            // cout << xx[i].a[j] << ' ' << xx[i].t[j] << endl;
        // }
    }
    while (q -- )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", Query(x, y));
    }
    return 0;
}