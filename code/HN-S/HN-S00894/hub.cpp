#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int c, t, n, k, x, y, cnt, pos = -1, dep[N], deg[N], dp[N][22];
vector<int> v[N];
void dfs(int cur, int fa){
    cout << cur;
    dep[cur] = deg[cur] = dep[fa] + 1;
    dp[cur][0] = fa;
    for(int i = 1; (1 << i) <= dep[cur]; i++){
        dp[cur][i] = dp[dp[cur][i - 1]][i - 1];
    }
    for(auto i : v[cur]){
        if(i != fa){
            dfs(i, cur);
            deg[cur] = max(deg[cur], deg[i]);
        }
    }
}
int lca(int x, int y){
    if(dep[x] < dep[y]){
        swap(x, y);
    }
    for(int i = 20; i >= 0; i--){
        if(dep[dp[x][i]] <= dep[y]){
            x = dp[x][i];
        }
    }
    if(x == y){
        return x;
    }
    for(int i = 20; i >= 0; i--){
        if(dp[x][i] != dp[y][i]){
            x = dp[x][i], y = dp[y][i];
        }
    }
    return dp[x][0];
}
int dis(int x, int y){
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
bool cmp(int x, int y){
    return deg[x] > deg[y];
}
int get(int x, int l){
    for(int i = 20; i >= 0 && l != 0; i--){
        if((1 << i) <= l){
            l -= (1 << i), x = dp[x][i];
        }
    }
    return x;
}
void work(int cur, int fa, int l){
    for(auto i : v[cur]){
        if(i != fa){
            work(i, cur, l);
        }
    }
    if(dis(pos, cur) > l){
        cnt++, pos = get(cur, min(l, dep[cur]));
    }
}
bool check(int mid){
    cnt = 0, pos = -1;
    work(1, 0, mid);
    return (cnt <= k);
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dep[0] = -1;
    dfs(1, 0);
    int l = 0, r = n - 1, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid, r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
