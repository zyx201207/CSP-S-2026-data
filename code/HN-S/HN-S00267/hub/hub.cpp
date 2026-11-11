#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5, INF = 1e18;
int n, K;
vector <int> g[N];
namespace baoli{
    int dist[15], dis[15];
    bool yf[15];
    void dfs(int u, int fu){
        dist[u] = min(dist[u], dis[u]);
        for(int v : g[u]){
            if(v == fu) continue;
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
        return ;
    }
    int pre[15];
    bool vis[15];
    int fd(int x){
        if(x == pre[x]) return x;
        else return pre[x] = fd(pre[x]);
    }
    void ut(int x, int y){
        x = fd(x), y = fd(y);
        if(x == y) return ;
        pre[y] = x;
        return ;
    }
    bool check(){
        for(int i = 1; i <= n; i++){
            pre[i] = i;
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            if(!yf[i]) continue;
            for(int v : g[i]){
                if(!yf[v]) continue;
                ut(i, v);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!yf[i]) continue;
            if(!vis[fd(i)]){
                vis[fd(i)] = true;
                cnt++;
            }
        }
        return cnt <= 2;
    }
    void solve(){
        int ans = INF;
        for(int mask = 0; mask < (1LL << n); mask++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if((mask >> j) & 1){
                    cnt++;
                    yf[j + 1] = true;
                }else{
                    yf[j + 1] = false;
                }
            }
            if(!check()) continue;
            if(cnt != K) continue;
            for(int i = 1; i <= n; i++) dist[i] = INF;
            for(int i = 1; i <= n; i++){
                if(yf[i]){
                    dist[i] = dis[i] = 0;
                    dfs(i, 0);
                }
            }
            int res = 0;
            for(int i = 1; i <= n; i++) res = max(res, dist[i]);
            ans = min(ans, res);
        }
        cout << ans << '\n';
        return ;
    }
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--){
        cin >> n >> K;
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n <= 10){
            baoli::solve();
            continue;
        }
    }
    return 0;
}
/*
邦吧邦吧邦吧哦！
窗外的天气 呜！
就像是 你多变的表情。
下雨了 雨陪我哭泣。
看不清 我也不想看清 哦！
离开你 我安静地抽离。
不忍揭晓的剧情。
我的泪流在心底 学会放弃～
*/