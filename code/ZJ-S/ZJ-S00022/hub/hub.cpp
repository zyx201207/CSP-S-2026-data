#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;
const int INF = 0x3f3f3f3f;
int n, k, res[MAXN], vis[MAXN], isGet[MAXN], cnt, visForCheck[MAXN], ans;
vector <int> edge[MAXN];

void dij(int s){
    memset(res, 0x3f, sizeof(res));
    memset(vis, 0, sizeof(vis));
    res[s] = 0;
    priority_queue <pair<long long, int> > q;
    q.push({0, s});
    while (!q.empty()){
        int u = q.top().second;
        q.pop();
        if (vis[u]){
            continue;
        }
        vis[u] = 1;
        int sz = edge[u].size();
        for (int i = 0; i < sz; i++){
            int v = edge[u][i];
            if (res[v] > res[u]+1){
                res[v] = res[u]+1;
                q.push({-res[v], v});
            }
        }
    }
}

void check(int node, bool isGeted){
    if (isGeted && !isGet[node]){
        cnt++;
    }
    int sz = edge[node].size();
    bool flag = 1;
    for (int i = 0; i < sz; i++){
        if (!visForCheck[edge[node][i]]){
            visForCheck[edge[node][i]] = 1;
            check(edge[node][i], isGet[node]);
            flag = 0;
        }
    }
    if (flag){
        cnt++;
    }
}

void dfs(int step, int get){
    if (step > n){
        cnt = 0;
        visForCheck[1] = 1;
        check(1, isGet[1]);
        if (cnt > 2){
            return ;
        }
        if (get != k){
            return ;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (!isGet[i]){
                dij(i);
                int mnd = INF;
                for (int j = 1; j <= n; j++){
                    if (isGet[j]){
                        mnd = min(mnd, res[j]);
                    }
                }
                sum = max(mnd, sum);
            }
        }
        ans = min(ans, sum);
        return ;
    }
    if (get > k){
        return ;
    }
    if (get == k){
        dfs(n+1, k);
        return ;
    }
    dfs(step+1, get);
    isGet[step] = 1;
    dfs(step+1, get+1);
    isGet[step] = 0;
}

int main(){ freopen("hub.in", "r", stdin);
            freopen("hub.out", "w", stdout);
            int _, T; cin >> _ >> T; while (T--)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        edge[i].clear();
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(isGet, 0, sizeof(isGet));
    ans = INF;
    dfs(1, 0);
    cout << ans << "\n";
}}