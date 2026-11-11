#include <cstdio>
#include <vector>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, x, y;
vector<int> w;
vector<pair<int, int>> linei;
vector<vector<long long>> dp;

long long min(long long a, long long b)
{
    return b < a ? b : a;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    w.assign(m, 0);
    dp.assign(m, vector<long long>(m, INF));
    for (int i = 0; i < m; ++i)
        scanf("%d", &w.at(i));
    for (int i = 0; i < n; ++i)
    {
        int k;
        scanf("%d", &k);
        linei.assign(k, pair<int, int>());
        for (int j = 0; j < k; ++j)
        {
            scanf("%d%d", &linei.at(j).first, &linei.at(j).second);
            --linei.at(j).first;
            for (int l = 0; l <= j; ++l)
            {
                int u = linei.at(l).first, v = linei.at(j).first;
                dp.at(u).at(v) = dp.at(v).at(u) = min(dp.at(u).at(v), linei.at(l).second + linei.at(j).second);
            }
        }
    }
    for (int l = 0; l < m; ++l)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(l) + dp.at(l).at(j));
    while (q--)
    {
        scanf("%d%d", &x, &y);
        --x;
        --y;
        printf("%lld\n", w.at(x) + dp.at(x).at(y) + w.at(y));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
