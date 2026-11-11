#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

static constexpr int MAX_SIZE = 100;

int nodes_cnt, target;
static std::vector<int> adj[MAX_SIZE + 5];
static bool used[MAX_SIZE + 5];
static int father[MAX_SIZE + 5];
static int dist[MAX_SIZE + 5];

static void solve();
static void init();
static int find_root(int x);
static void dfs(int start, int node, int parent, int d);

int main() {
    std::freopen("hub.in", "r", stdin);
    std::freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_id, tests_cnt;
    std::cin >> test_id >> tests_cnt;
    for (int i = 1; i <= tests_cnt; i++) {
        solve();
    }

    return 0;
}

static void solve() {
    std::cin >> nodes_cnt >> target;
    for (int i = 1; i <= nodes_cnt; i++) {
        adj[i].clear();
    }
    for (int i = 1; i < nodes_cnt; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int answer = 1e9;
    int max_mask = (1 << nodes_cnt) - 1;
    for (int mask = 0; mask <= max_mask; mask++) {
        if (__builtin_popcount(mask) != target) {
            continue;
        }
        init();
        for (int i = 1; i <= nodes_cnt; i++) {
            if ((mask & (1 << (i - 1))) != 0) {
                used[i] = true;
            }
        }
        for (int i = 1; i <= nodes_cnt; i++) {
            if (!used[i]) {
                continue;
            }
            for (int to : adj[i]) {
                if (used[to]) {
                    int x = find_root(i);
                    int y = find_root(to);
                    if (x != y) {
                        father[y] = x;
                    }
                }
            }
        }
        std::set<int> root_cnt;
        for (int i = 1; i <= nodes_cnt; i++) {
            if (used[i]) {
                root_cnt.insert(find_root(i));
            }
        }
        if (root_cnt.size() > 2) {
            continue;
        }

        int result = 0;
        for (int i = 1; i <= nodes_cnt; i++) {
            dfs(i, i, 0, 0);
            result = std::max(result, dist[i]);
        }
        answer = std::min(answer, result);
    }

    std::cout << answer << '\n';
}

static void init() {
    for (int i = 1; i <= nodes_cnt; i++) {
        father[i] = i;
        used[i] = false;
        dist[i] = 1e9;
    }
}

static int find_root(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_root(father[x]);
}

static void dfs(int start, int node, int parent, int d) {
    if (used[node]) {
        dist[start] = std::min(dist[start], d);
    }
    for (int to : adj[node]) {
        if (to == parent) {
            continue;
        }
        dfs(start, to, node, d + 1);
    }
}
