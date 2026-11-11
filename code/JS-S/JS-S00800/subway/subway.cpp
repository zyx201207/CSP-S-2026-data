#include <bits/stdc++.h>
#define int long long
#define SIZE 500005
using namespace std;

int c, n, m, d, q;
int gate_time[SIZE], stat_occp_cnt[SIZE];
// Linking, distance
const int stations_dist = 22;
const int inf = 1e18;
vector<pair<int, int>> edge[SIZE * stations_dist];
int dijkstra(int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    vector<int> dis(SIZE * stations_dist, inf);
    dis[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        auto fr_pr = pq.top();
        pq.pop();
        const auto cur = fr_pr.second, c_dis = fr_pr.first;
        if (cur == t)
        {
            break;
        }
        if (dis[cur] < c_dis)
        {
            continue;
        }
        for (auto nxt_pr : edge[cur])
        {
            const auto link = nxt_pr.first, cost = nxt_pr.second;
            if (c_dis + cost < dis[link])
            {
                dis[link] = c_dis + cost;
                pq.push({dis[link], link});
            }
        }
    }
    return dis[t];
}
signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    // Don't forget to add the platform to gate time!!!
    for (int i = 1; i <= m; i++)
    {
        cin >> gate_time[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int line_stat_cnt;
        cin >> line_stat_cnt;
        int last_station = 0;
        for (int j = 1; j <= line_stat_cnt; j++)
        {
            int cur_station, transfer_time;
            cin >> cur_station >> transfer_time;
            stat_occp_cnt[cur_station]++;
            int cur_stat_node = cur_station * stations_dist;
            int cur_line_node = cur_stat_node + stat_occp_cnt[cur_station];
            edge[cur_stat_node].push_back({cur_line_node, transfer_time});
            edge[cur_line_node].push_back({cur_stat_node, transfer_time});
            if (last_station != 0)
            {
                int last_line_node = last_station * stations_dist + stat_occp_cnt[last_station];
                edge[last_line_node].push_back({cur_line_node, 0});
                edge[cur_line_node].push_back({last_line_node, 0});
            }
            last_station = cur_station;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int s, t;
        cin >> s >> t;
        if (s > t)
        {
            // Ensure s < t
            swap(s, t);
        }
        int ans = dijkstra(s * stations_dist, t * stations_dist) + gate_time[s] + gate_time[t];
        cout << ans << "\n";
    }

    return 0;
}