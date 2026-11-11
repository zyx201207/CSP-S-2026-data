#include <bits/stdc++.h>
using namespace std;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
void print(const vector<int>& arr) {
    for (auto &c: arr)cout << c << ' ';cout << endl;}
void g() {
#ifndef PDEBUG
auto _1 = freopen("subway.in", "r", stdin);auto _2 = freopen("subway.out", "w", stdout);
#endif
}

struct Station {
    int exit_to_ting;
    vector<int> including_lines;
} stations[MAXN];

int t[MAXN][MAXN];

struct Line {
    vector<int> passer;
} lines[MAXN];

struct Path {
    int last_line, current_line, station;
    bool enter, new_line, out;
};

struct Search {
    int min_time = 1e9;
    bitset<MAXN> vis;
    int cur_plan_begin, cur_plan_end;

    void dfs(vector<Path> path, int last_line, int cur_line, int cur_station) {
        Path p = {last_line, cur_line, cur_station, cur_station == cur_plan_begin, last_line != cur_line, cur_station == cur_plan_end};
        path.push_back(p);
        if (cur_station == cur_plan_end) {
            int time = 0;
            for (auto &p: path) {
                if (p.enter || p.out) {
                    time += stations[p.station].exit_to_ting + t[p.station][p.current_line];
                }
                if (p.new_line)  {
                    time += t[p.station][p.last_line] + t[p.station][p.current_line] * 2;
                }
            }
            // cout << time << endl;
            min_time = min(time, min_time);
        }
        for (auto &l: stations[cur_station].including_lines) {
            for (auto &s: lines[l].passer) {
                if (vis[s]) continue;
                vis[s] = 1;
                dfs(path, cur_line, l, s);
            }
        }

    }        
};

int main() {
    g();
    // testcase id, line.cnt, station.cnt, max_pass_by, plans
    int testcase, linecnt, stationcnt, mbp, plancnt;
    cin >> testcase >> linecnt >> stationcnt >> mbp >> plancnt;
    for (int i = 1; i <= stationcnt; ++i) cin >> stations[i].exit_to_ting;
    // input: a_i, k_i
    for (int i = 1; i <= linecnt; ++i) {
        int ki; cin >> ki;
        for (int k = 1; k <= ki; ++k) {
            int pk; cin >> pk;
            lines[i].passer.push_back(pk);
            // cout << "for line #" << i << ", station #" << pk << " is included." << endl;
            stations[i].including_lines.push_back(i);
            cin >> t[pk][i];
            // cout << "from station #" << k << ", to station of line #" << i << " needs " << t[pk][i] << endl;
        }
    }

    // begin/end of #r
    // for (int i = 1; i <= plancnt; ++i) cin >> plans[i].begin >> plans[i].end;
    for (int i = 1; i <= plancnt; ++i) {
        int begin, end; cin >> begin >> end;
        Search search;
        search.vis.reset();
        search.vis[begin] = 1;
        search.cur_plan_begin = begin;
        search.cur_plan_end = end;
        int ans = 1e9;
        search.vis[search.cur_plan_begin] = 1;
        for (auto &l: stations[begin].including_lines) {
            search.dfs({}, l, l, begin);
            ans = min(ans, search.min_time);
        }
        cout << ans << endl;
    }

    return 0;
}

/**
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

Case #0, 2 lines, 5 stations, max_passing_by=20, 2 plans
From station to ting,
#     1 2 3 4 5
takes 4 1 9 2 5 s.
// 3 | 1 [5] 2 [7] 4 [6]
// 3 | 2 [3] 3 [4] 5 [7]
line #1 contains 1, 2, 4
line #2 contains 2, 3, 5
t:
    1 2 3
  /-_____
1 | 5 7 6
2 | 3 4 7
---
1 3
1 2
**/