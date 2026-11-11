#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>


using i64 = long long;


inline i64 read()
{
    i64 x = 0, f = 1;
    char ch = getchar_unlocked();
    while (!(ch >= '0' && ch <= '9'))
    {
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x * 10) + (ch - 48);
        ch = getchar_unlocked();
    }
    return x * f;
}



void dfs(i64 p, std::vector<i64>& cost, std::vector<i64>& vis, i64 n, i64 m, i64 d, std::vector<std::vector<i64> >& ka, std::vector<std::vector<i64> >& kt)
{
    return;
}


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
    i64 c = read(), d = read(), n = read(), m = read(), q = read();
    std::vector<i64> w(m + 1);
    for (i64 i = 1; i <= m; i++) w[i] = read();
    std::vector<std::vector<i64> > ka(n, std::vector<i64>(1, 0));
    std::vector<std::vector<i64> > kt(n, std::vector<i64>(1, 0));
    std::vector<std::vector<i64> > table(n);
    for (i64 i = 1; i <= n; i++)
    {
        ka[i][0] = read();
        ka[i].resize(ka[i][0]);
        kt[i][0] = ka[i][0];
        kt[i].resize(kt[i][0]);
        for (i64 j = 1; j <= ka[i][0]; j++)
        {
            ka[i][j] = read();
            kt[i][j] = read();
        }
    }
    std::i64 > x, y;
    vector<i64> cost(m + 1);
    vector<i64> vis(m + 1);
    for (i64 i = 1; i <= q; i++)
    {
        memset(cost.begin(), 0, sizeof(cost));
        memset(vis.begin(), 0, sizeof(vis));
        x = read();
        y = read();
        dfs(x, cost, vis);
        cout << cost[x] << endl;
    }
    //input finished!
    //let's try dfs
    //(maybe I'll get 24 points
    //no!!!!!!!
    return 0;
}
