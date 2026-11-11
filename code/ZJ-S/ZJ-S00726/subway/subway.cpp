#include <bits/stdc++.h>
using std::cin; using std::cout; using std::cerr; using std::string; using std::endl; using std::vector; using std::min; using std::max; using std::sort;
#define ll long long

struct edge {
    ll to, val, line;
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ll c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector <ll> ground_to_station_times(m);
    for (ll i = 0; i < m; ++i) cin >> ground_to_station_times[i];
    vector <std::unordered_map <ll, ll>> inside_station_times(m);
    vector <vector <edge>> edges(m);
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        vector <ll> stations(k);
        for (ll j = 0; j < k; ++j) {
            ll station, walk_time;
            cin >> station >> walk_time;
            --station;
            inside_station_times[station][i] = walk_time;
            stations[j] = station;
        }
        for (ll x = 0; x < k; ++x) {
            for (ll y = 0; y < k; ++y) {
                if (x == y) continue;
                edge a_edge;
                a_edge.to = stations[y], a_edge.val = inside_station_times[stations[x]][i] + inside_station_times[stations[y]][i], a_edge.line = i;
                edges[stations[x]].push_back(a_edge);
            }
        }
    }

    for (ll qq = 0; qq < q; ++qq) {
        ll s, t;
        cin >> s >> t;
        --s; --t;
        if (c >= 12 && c <= 19) {
            vector <ll> last_point(m, -2);
            last_point[s] = -1;
            std::queue <ll> q;
            q.push(s);
            ll ans = 0;
            while (!q.empty()) {
                ll point = q.front();
                q.pop();
                for (edge a_edge : edges[point]) {
                    if (last_point[a_edge.to] != -2) continue;
                    last_point[a_edge.to] = point;
                    q.push(a_edge.to);
                    if (a_edge.to == t) break;
                }
            }
            ll last = last_point[t];
            while (last != -1) {
				ans += edges[0][0].val;
				last = last_point[last];
            }
            cout << ans + ground_to_station_times[s] + ground_to_station_times[t] << '\n';
        } else {
            std::priority_queue <std::pair <ll, ll>, vector <std::pair <ll, ll>>, std::greater <std::pair <ll, ll>>> pq;
            vector <ll> dis(m, 9223372036854775807);
            dis[s] = 0;
            pq.push({0, s});
            while (!pq.empty()) {
                std::pair <ll, ll> state = pq.top();
                pq.pop();
                if (state.first > dis[state.second]) continue;
                for (edge &a_edge : edges[state.second]) {
                    if (state.first + a_edge.val < dis[a_edge.to]) {
                        dis[a_edge.to] = state.first + a_edge.val;
                        pq.push({dis[a_edge.to], a_edge.to});
                    }
                }
            }
            cout << dis[t] + ground_to_station_times[s] + ground_to_station_times[t] << '\n';
        }
    }

    return 0;
}