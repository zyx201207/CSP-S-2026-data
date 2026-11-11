#include <bits/stdc++.h>
using namespace std;

vector <int> G[100011];
int dis1[100011];
int dis2[100011];
int vis[100011];
int dis[1001][1001];

void dfs(int p, int dis[100011]){
    for(auto x : G[p]){
        if(dis[x] == 0){
            dis[x] = dis[p] + 1;
            dfs(x, dis);
        }
    }
    return ;
}

void solve2(){
    int n, k, u, v;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) G[i].clear();
    for(int i = 1;i < n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dis1, 0, sizeof(dis1));
    dis1[1] = 1;
    dfs(1, dis1);
    int mx = 1;
    for(int i = 1;i <= n;i++){
        if(dis1[i] > dis1[mx]) mx = i;
    }
    memset(dis2, 0, sizeof(dis2));
    dis2[mx] = 1;
    dfs(mx, dis2);
    for(int i = 1;i <= n;i++){
        if(dis2[i] > dis2[mx]) mx = i;
    }
    cout << (dis2[mx]) / 3 << "\n";
    return ;
}

void dfs2(int p, int mask){
    for(auto x : G[p]){
        if(vis[x] || !(1 & (mask >> (x - 1)))) continue;
        vis[x] = 1;
        dfs2(x, mask);
    }
    return ;
}

void solve(){
    int n, k, u, v;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        G[i].clear();
    }
    for(int i = 1;i < n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mn = 1e9;
    for(int mask = 1;mask < (1 << n);mask++){
        //cout << bitset<8>(mask) << "\n";
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(1 & (mask >> (i - 1))){
                cnt++;
            }
        }
        if(cnt != k) continue;
        //cout << "!" << bitset<8>(mask) << "\n";
        cnt = 0;
        for(int i = 1;i <= n;i++) vis[i] = 0;
        for(int i = 1;i <= n;i++){
            if(1 & (mask >> (i - 1)) && !vis[i]){
                cnt++;
                dfs2(i, mask);
            }
        }
        if(cnt > 2) continue;
        //cout << "!!!" << bitset<8>(mask) << "\n";
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = 1e9;
            }
        }
        for(int i = 1;i <= n;i++){
            for(auto x : G[i]){
                dis[i][x] = 1;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
        int mx = -1;
        for(int i = 1;i <= n;i++){
            if(1 & (mask >> (i - 1))) continue;
            int mn2 = 1e9;
            for(int j = 1;j <= n;j++){
                if(!(1 & (mask >> (j - 1)))) continue;
                mn2 = min(mn2, dis[i][j]);
            }
            mx = max(mx, mn2);
        }
        //cout << "!!!" << mx << "!!!\n";
        mn = min(mn, mx);
    }
    cout << mn << "\n";
    return ;
}

int main(){
    //17:05:16 tried subtask 11-12 but gave up(not same as what i thought)
    //17:45:48 i found i can easily get points in subtask 1-3, so i will try them
    //18:04:19 finish subtask 1-3(task correct, but the input is small and i don't sure whether i can get points)
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t--){
            solve2();
        }
    }
    else{
        while(t--){
            solve();
        }
    }
}
