#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
// #define dep(i,r,l) for(int i = r; i >= l; i--)
#define lc (idx << 1)
#define rc (idx << 1 | 1)

using namespace std;

int c, t;
int n, k;
int u, v;
const int maxn = 1e6 + 100;
vector<int> tree[maxn];
vector<int> bit;
int fa[maxn];
int dep[maxn];
int fat[30][30];
int chose[100];

void dfs(int x, int fa){
    dep[x] = dep[fa] + 1;
    fat[0][x] = fa;
    for(auto i : tree[x]){
        if(i == fa) continue;
        else dfs(i,x);
    }
}

void initst(){
    rep(i,1,20){
        rep(j,1,n){
            fat[i][j] = fat[i-1][fat[i-1][j]];
        }
    }
}

int lca(int x, int y){
    if(dep[x] > dep[y]){
        swap(x,y);
    }
    for(int i = 20; i >= 0; i--){
        if(dep[fat[i][y]] >= dep[x]){
            y = fat[i][y];
        }
    }
    if(x == y){
        return x;
    }
    for(int i = 20; i >= 0; i--){
        if(fat[i][x] == fat[i][y])continue;
        x = fat[i][x];
        y = fat[i][y];
    }
    return fat[0][x];
}

int dist(int x, int y){
    return (dep[x] + dep[y] - 2 * dep[lca(x,y)]);
}

int ffa(int x){
    if(fa[x] == x){
        return x;
    } else {
        fa[x] = ffa(fa[x]);
        return fa[x];
    }
}

void getbit(int cur){
    bit.clear();
    rep(i,0,n){
        if((1<<i) & cur){
            bit.push_back((i+1));
            chose[(i+1)] = 1;
        }
    }
}

void uni(int x, int y){
    int fa1 = ffa(x), fa2 = ffa(y);
    if(fa1 == fa2){
        return;
    } else {
        fa[fa1] = fa2;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    cin >> c >> t;
    
    while(t--){
        if(c <= 3){
            int res = LONG_LONG_MAX;
            cin >> n >> k;
            rep(i,1,(n)){
                tree[i].clear();
            }
            rep(i,1,n){
                dep[i] = 0;
            }
            rep(i,1,(n-1)){
                cin >> u >> v;
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            rep(i,0,20){
                rep(j,1,20){
                    fat[i][j] = 0;
                }
            }
            dfs(1,0);
            initst();
            int mx = (1 << n) - 1;
            rep(i,0,mx){
                rep(i,1,n){
                    chose[i] = 0;
                }
                getbit(i);
                if(bit.size() == k){
                    rep(i,1,n){
                        fa[i] = i;
                    }
                    for(int v1 : bit){
                        for(int u1 : tree[v1]){
                            if(chose[u1]){
                                uni(v1,u1);
                            }
                        }
                    }
                    set<int> vfa;
                    for(int v1 : bit){
                        vfa.insert(ffa(v1));
                    }
                    int cur = -1;
                    if(vfa.size() <= 2){
                        rep(j,1,n){
                            int curdist = LONG_LONG_MAX;
                            for(int v1 : bit){
                                curdist = min(curdist, dist(j,v1));
                            }
                            cur = max(cur, curdist);
                        }
                        res = min(res, cur);
                    }
                }
            }
            cout << res << "\n";
        }
    }

    return 0;
}