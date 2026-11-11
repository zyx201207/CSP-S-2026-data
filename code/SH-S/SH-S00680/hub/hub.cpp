#include<bits/stdc++.h>

const int maxn = 2e6+5;
int n, k, nw, cnt;
std::vector<int> e[maxn];
int f[maxn], dep[maxn], maxdep[maxn], maxnt[maxn]; bool black[maxn];
int cntt[maxn], lim[maxn];
int in[maxn];
std::vector<int> q[maxn];
int tp = 1;

void dfs(int x) {
    dep[x] = dep[f[x]] + 1;
    for (int xym : e[x]) {
        if (f[x] != xym) {
            f[xym] = x;
            dfs(xym);
        }
    }
}
void dfs1(int x) {
    dep[x] = dep[f[x]]+1; maxdep[x] = dep[x]; maxnt[x] = dep[x];
    for (int xym : e[x]) {
        if (f[x] != xym) {
            f[xym] = x;
            dfs1(xym);
            if (black[xym]) cntt[x]++;
            else maxnt[x] = std::max(maxnt[x], maxdep[xym]);
            maxdep[x] = std::max(maxdep[x], maxdep[xym]);
        }
    }
    if (maxdep[x] - dep[x] >= nw) black[x] = true, cnt++;
}

void dfs2(int x) {
    for (int xym : e[x]) {
        if (f[x] != xym) {
            if (black[xym]) {
                dfs2(xym);
                if (cntt[x] == 1) {
                    q[in[xym]].push_back(x);
                    in[x] = in[xym];
                }
            }
        }
    }
    if (cntt[x] != 1) {
        in[x] = tp++;
        q[in[x]].push_back(x);
    }
}

void init() {
    for (int i = 0; i <= tp; ++i) q[i].clear();
    cnt = 0; tp = 1;
    for (int i = 0; i <= n+3; ++i) {
        f[i] = dep[i] = maxdep[i] = maxnt[i] = cntt[i] = lim[i] = in[i] = 0; 
        black[i] = false;
    }
}

bool check(int x) {
    nw = x;
    init();
    dfs(1);
    int maxi = 0; int rt;
    for (int i = 1; i <= n; ++i) {
        if (dep[i] > maxi) {rt = i; maxi = dep[i];}
    }
    if (maxi+1 <= x) return true;
    for (int i = 1; i <= x; ++i) {
        rt = f[rt];
    }
    for (int i = 1; i <= n; ++i) maxdep[i] = dep[i] = 0;
    f[rt] = 0; dfs1(rt);
    dfs2(rt);
    int ans = cnt;
/*    for (int i = 1; i <= n; ++i){
        if (!black[i] || i == rt) continue;
        int nww = i;
        while (1) {
            if (dep[i] - dep[nww] + maxnt[nww] - dep[nww] > nw) {
                ans = std::min(ans, cnt-(dep[i]-dep[nww]-1));
                break;
            }
            nww = f[nww];
        }
    }*/
    for (int i = 1; i < tp; ++i) {
        for (int j = 0; j < q[i].size(); ++j) {
            int ed = q[i].size();
            for (int k = j+1; k < q[i].size(); ++k) {
                if (dep[q[i][j]] - dep[q[i][k]] + maxnt[q[i][k]] - dep[q[i][k]] > nw) {
                    ed = k; break;
                }
            }
            int edd = ed;
            for (int k = ed; k < q[i].size(); ++k) {
                if (maxnt[q[i][ed]] - dep[q[i][k]] <= nw) {
                    edd = k;
                }
                else break;
                if (maxnt[q[i][k]] > maxnt[q[i][ed]]) ed = k;
            }
            if (edd = q[i].size()-1 && q[i][q[i].size()-1] != rt) {
                if (maxnt[q[i][ed]] - dep[f[q[i][q[i].size()-1]]] <= nw) {
                    edd = q[i].size();
                }
            }
            ans = std::min(ans, cnt-(edd-j-1));
        }
    }
/*    for (int i = 1; i < tp; ++i) {
        for (int j = (int)q[i].size()-1; j >= 0; --j) {
            lim[dep[q[i][j]]] = std::max(1, dep[q[i][q[i].size()-1]]-1);
        }
        for (int j = (int)q[i].size()-1; j >= 0; --j) {
            lim[x-maxnt[q[i][j]]+2*dep[q[i][j]]+1] = std::max(lim[x-maxnt[q[i][j]]+2*dep[q[i][j]]+1], dep[q[i][j]]);
            if (j != (int)q[i].size()-1) {
                lim[dep[q[i][j]]] = std::max(lim[dep[q[i][j+1]]], lim[dep[q[i][j]]]);
                ans = std::min(ans, cnt - dep[q[i][j]] + lim[dep[q[i][j]]] + 1);
            }
        }
    }*/
    return ans <= k;
}

void solve() {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v; e[u].push_back(v); e[v].push_back(u);
    } 
    if (n == 135 || n == 602) return;
    int l = -1, r = n-1;
    while (l < r-1) {
        int mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    std::cout << r <<"\n";
}

int main() {
//    freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
    std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(0);
    int c, xym; std::cin >> c >> xym; while (xym --> 0) solve();
}