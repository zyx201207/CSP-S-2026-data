#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define usize size_t
#define Vec vector
#define String string

struct To {
    usize idx;
    i64 cost;
};
struct Schedule {
    usize start;
    usize end;
};
struct Side {
    usize next;
    i64 cost;
};
struct Node {
    usize idx;
    i64 cost;
    bool operator>(const Node other) const {
        return cost > other.cost;
    }
};

i64 find_smallest(Vec<Vec<Side>> &mp, usize start, usize end) {
    Vec<i64> dis(mp.size(), 1e18);
    Vec<bool> walked(mp.size(), false);
    dis[start] = 0;
    priority_queue<Node, Vec<Node>, greater<Node>> q;
    q.push(Node{start, 0});
    while (!q.empty()) {
        usize idx = q.top().idx;
        q.pop();
        if (walked[idx]) continue;
        else walked[idx] = true;
        for (usize i = 0; i < mp[idx].size(); i++) {
            usize u = idx;
            usize v = mp[idx][i].next;
            if (dis[u] + mp[idx][i].cost < dis[v]) {
                dis[v] = dis[u] + mp[idx][i].cost;
                q.push(Node{v, dis[v]});
            }
        }
    }
    return dis[end];
}

Vec<i64> solve(Vec<i64> &bases, Vec<Vec<To>> &lines, Vec<Schedule> &schedules) {
    Vec<Vec<Side>> mp(bases.size() + lines.size());
    // points of lines 's idx = station_num + 1 + line_idx
    for (usize i = 0; i < lines.size(); i++) {
        usize u = bases.size() + i;
        for (usize j = 0; j < lines[i].size(); j++) {
            usize v = lines[i][j].idx;
            i64 cost = lines[i][j].cost;
            mp[u].push_back(Side{v, cost});
            mp[v].push_back(Side{u, cost});
        }
    }
    
    Vec<i64> anses(schedules.size());
    for (usize i = 0; i < schedules.size(); i++) {
        usize start = schedules[i].start;
        usize end = schedules[i].end;
        i64 ans = bases[start] + bases[end];
        ans += find_smallest(mp, start, end);
        anses[i] = ans;
    }
    return anses;
}

i32 main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    usize piont_idx;
    usize way_num;
    usize station_num;
    usize max_pass;
    usize que_num;
    cin >> piont_idx >> way_num >> station_num >> max_pass >> que_num;
    Vec<i64> bases(station_num + 1, 1e18);
    for (usize i = 1; i <= station_num; i++) cin >> bases[i];
    Vec<Vec<To>> lines(way_num);
    for (usize i = 0; i < way_num; i++) {
        usize pass_num;
        cin >> pass_num;
        lines[i].resize(pass_num);
        for (usize j = 0; j < pass_num; j++)
            cin >> lines[i][j].idx >> lines[i][j].cost;
    }
    Vec<Schedule> schedules(que_num);
    for (usize i = 0; i < que_num; i++) {
        cin >> schedules[i].start >> schedules[i].end;
    }

    Vec<i64> ans = solve(bases, lines, schedules);
    for (usize i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}