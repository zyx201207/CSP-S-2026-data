#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <bitset>
#define ll long long

using namespace std;

const int maxn = 15, INF = 1e9;
int c, T, n, k, fa[maxn][20], dep[maxn], ans;
bool vis[maxn];
vector <int> E[maxn];
vector <int> st;

bool cmp(int x, int y){
    return dep[x] < dep[y];
}

void dfs(int u){
    dep[u] = dep[fa[u][0]]+1;
    for(int i = 0; i < E[u].size(); i++){
        int v = E[u][i];
        if(v == fa[u][0]) continue;
        fa[v][0] = u;
        dfs(v);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = 10; i >= 0; i--)
        if(dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if(u == v) return u;
    for(int i = 10; i >= 0; i--)
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i], v = fa[v][i];
        }
    return fa[u][0];
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--){
        scanf("%d%d", &n, &k);
        ans = INF;
        for(int i = 1; i <= n; i++){
            E[i].clear();
            fa[i][0] = 0, dep[i] = 0;
        }
        for(int i =1, u, v; i < n; i++){
            scanf("%d%d", &u, &v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        dfs(1);
        for(int j = 1; j <= 10; j++)
            for(int i = 1; i <= n; i++)
                fa[i][j] = fa[fa[i][j-1]][j-1];
        for(int t = 0; t < (1<<n); t++){
            int cnt = 0, block = 0;
            st.clear();
            for(int j = 0; j < n; j++){
                if(t & (1<<j)){
                    cnt++, vis[j+1] = 1;
                    st.push_back(j);
                }
                else vis[j+1] = 0;
            }
            if(cnt != k) continue;
            sort(st.begin(), st.end(), cmp);
            for(int j = 1; j <= n; j++)
                if(vis[j] && !vis[fa[j][0]])
                    block++;
            if(block != 2) continue;
            int res = 0;
            for(int i = 1; i <= n; i++){
                if(vis[i]) continue;
                int dis = INF;
                for(int j = 1; j <= n; j++)
                    if(vis[j])
                        dis = min(dis, dep[i] + dep[j] - 2*dep[lca(i,j)]);
                res = max(res, dis);
            }
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}
