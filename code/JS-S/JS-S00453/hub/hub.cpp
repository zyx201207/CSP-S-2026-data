#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 5010; // just all n^2
vector<int> edge[MAX_N];

int dis[MAX_N][MAX_N];

int choice[MAX_N];

void calc(const int rt, const int u, const int f, const int ds = 0) {
    dis[rt][u] = ds;
    for(const auto v : edge[u]) {
        if(v != f) calc(rt, v, u, ds + 1);
    }
}

bool flag;
int cnt = 0;
void check(const int u, const int f, const int p) {
    if(flag == false) return ;
    if(choice[u] == 0) return;
    if(p != choice[u]) flag = false;
    ++ cnt;
    for(const auto v : edge[u]) {
        if(v != f) check(v, u, p);
    }
}

int ans = 0x3f3f3f3f;

void dfs(const int n, const int k, const int deep = 1, const int kk = 0) {
    if(kk > k) return;
    if(deep > n) {
        if(kk != k) return;
        vector<int> cc1, cc2;
        for(int i=1;i<=n;i++) {
            if(choice[i] == 1) {
                cc1.push_back(i);
            } else if(choice[i] == 2) {
                cc2.push_back(i);
            }
        }
        if(cc1.empty() || cc2.empty()) return;
        flag = true; cnt = 0;
        check(cc1.front(), 0, 1);
        if(flag == false || cnt != (int) cc1.size()) return;
        flag = true; cnt = 0;
        check(cc2.front(), 0, 2);
        if(flag == false || cnt != (int) cc2.size()) return;
        
        
        int mx = 0;
        for(int i=1;i<=n;i++) {
            int mn = 0x3f3f3f3f;
            for(const auto x : cc1) {
                mn = min(mn, dis[i][x]);
            }
            for(const auto x : cc2) {
                mn = min(mn, dis[i][x]);
            }
            mx = max(mx, mn);
        }
        ans = min(mx, ans);
    } else {
        choice[deep] = 0;
        dfs(n, k, deep + 1, kk);
        choice[deep] = 1;
        dfs(n, k, deep + 1, kk+1);
        choice[deep] = 2;
        dfs(n, k, deep + 1, kk+1);
    }
}

void init() {
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(choice, 0, sizeof choice);
    ans = 0x3f3f3f3f;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    int c, T;
    cin >> c >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;
        for(int i=1;i<=n;i++) edge[i].clear();
        init();
        for(int i=1;i<n;i++) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(int i=1;i<=n;i++) calc(i, i, 0);

        dfs(n, k);

        cout << ans << '\n';
    }


    std::fclose(stdin);
    std::fclose(stdout);
    return 0;
}

/*
ideal condintion:
100pts + ~50pts + 8pts + 15pts.
~150 ~ 170 pts.
Is that enough ? ......
if not, never mind, maybe i will leave OI forever.
*/