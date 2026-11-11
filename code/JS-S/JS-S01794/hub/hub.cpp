#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
int c, t;
int n, k;
vector<int> e[N];
int z[N], f[N];
int ans = LONG_LONG_MAX;
void dfsu(int x) {
    f[x] = 0;
    for(auto xx : e[x]) {
        if(f[xx] == 1)
            dfsu(xx);
    }
}
void dfs(int dep) {
    if(dep == n + 1) {
        int b[N] = {0};
        memset(f, 0, sizeof f);
        int sum = 0;
        int top = 0;
        for(int i = 1; i <= n; i++) {
            if(z[dep] == 1)
                b[++top] = 1, f[top] = 1;
        } 
        if(top != k)
            return ;
        for(int i = 1; i <= n; i++) {
            if(f[i] == 1)
                dfsu(f[i]);
            sum ++;
        }
        if(sum > 2)
            return ;
        for(int i = 1; i <= n; i++)
            f[i] = b[i];
        for(int i = 1; i <= n; i++) {
            queue<pair<int, int>> q;
            q.push({i, 0});
            int mx = -1;
            while(!q.empty()) {
                pair<int, int> now = q.front();
                if(f[now.first])
                    break;  
                if(b[now.first])
                    {mx = max(mx, b[now.second]);break;}
                f[now.first] = 1;
                for(auto x : e[now.first]) {
                    q.push({x, now.second + 1});
                }
            }
            ans = min(ans, mx);
        }
        return ;
    }
    z[dep] = 1;
    dfs(dep + 1);
    z[dep] = 0;
    dfs(dep + 1);
}
signed mian() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        memset(z, 0, sizeof z);
        cin >> n >> k;
        for(int i = 1; i <= n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back(v), e[v].push_back(u);
        } 
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}