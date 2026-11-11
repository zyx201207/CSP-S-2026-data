#include <bits/stdc++.h>

using namespace std;
vector<int> wa;
int w_through[500005][505] = {0};
pair<int, int> subways[505][500005] = {}; // pair0 = a, pair1 = t
vector<pair<int, int>> plans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        int ka;
        cin >> ka;
        wa.push_back(ka);
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= 2 * k; j++)
        {
            cin >> subways[i][j].first;
            cin >> subways[i][j].second;
            w_through[subways[i][j].first][i] = 1;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int fi, se;
        cin >> fi >> se;
        plans.push_back({fi, se});
    }
    for (auto plan : plans)
    {
        int total = wa[plan.first] + wa[plan.second];
        int now_in_which_station = plan.first;
        while (1)
        {
            vector<int> noted_subway;
            for (int j = 1; j <= n; j++)
            {
                if (w_through[now_in_which_station][j] == 1)
                {
                    noted_subway.push_back(j);
                }
            }
            for (int j = plan.second; j >= now_in_which_station; j--)
            {
                bool flag = true;
                for (int sub : noted_subway)
                {
                    if (w_through[j][sub] == 1)
                    {
                        total += subways[sub][now_in_which_station].second + subways[sub][j].second;
                        now_in_which_station = j;
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (now_in_which_station == plan.second)
            {
                cout << total << "\n";
                break;
            }
        }
    }
    return 0;
}
