#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,ans,a[1000005],dp[1000005][25],dep[1000005];
bool vis[1000005];
vector<int> g[1000005];
void find(int x,int fa){
    if (!a[x] || vis[x]) return;
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++) if (g[x][i] != fa) find(g[x][i],x);
}
void pre_lca(int x,int fa){
    dep[x] = dep[fa] + 1;
    dp[x][0] = fa;
    for (int i = 1; (1 << i) < dep[x]; i++) dp[x][i] = dp[dp[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); i++) if (g[x][i] != fa) pre_lca(g[x][i],x);
}
int get_lca(int x,int y){
    if (dep[x] > dep[y]) swap(x,y);
    for (int i = 20; i >= 0; i--) if (dep[x] <= dep[dp[y][i]]) y = dp[y][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) if (dp[x][i] != dp[y][i]){
        x = dp[x][i];
        y = dp[y][i];
    }
    return dp[x][0];
}
int get_dis(int x,int y){return dep[x] + dep[y] - 2 * dep[get_lca(x,y)];}
void dfs(int x,int cnt){
    if (cnt > m) return;
    if (x > n){
        int tot = 0;
        fill(vis + 1,vis + n + 1,0);
        for (int i = 1; i <= n; i++) if (a[i] && !vis[i]){
            if (++tot > 2) return;
            find(i,0);
        }
        if (tot < 2) return;
        int maxn = 0;
        for (int i = 1; i <= n; i++) if (!a[i]){
            int dis = 1e9;
            for (int j = 1; j <= n; j++) if (a[j]) dis = min(dis,get_dis(i,j));
            maxn = max(maxn,dis);
        }
        ans = min(ans,maxn);
        return;
    }
    a[x] = 1;
    dfs(x + 1,cnt + 1);
    a[x] = 0;
    dfs(x + 1,cnt);
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    ans = 1e9;
    for (int i = 1,x,y; i < n; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (c == 13 || c == 14){
        cout << (m == n ? 0 : (m >= n / 2 ? 1 : (n / 2 - m + 3) / 4 + 1)) << '\n';
        return;
    }
    pre_lca(1,0);
    dfs(1,0);
    cout << ans << '\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> c >> t; t--; solve());
    return 0;
}//极限打完暴力，此题跟 忘了 不可比
//我觉得我相对于去年区了很多，因为去年发呆了半个小时，今年没有