#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 3;
int c, t, n, d;
int x[N];
vector<int> G[N];
int ans = 0;
struct Node{
    int y, v;
};
int dis[N];
inline bool bfs(int s, int ed){
    queue<Node> Q;
    memset(dis, 0x3f, sizeof dis);
    Q.push({s, 0});
    dis[s] = 0;
    int cnt = 0;
    while(!Q.empty()){
        auto u = Q.front().y;
        Q.pop();
        if(u == ed){
            ++cnt;
            continue;
        }
        for(auto y : G[u]){
            if(dis[y] >= dis[u] + 1){
                dis[y] = dis[u] + 1;
                Q.push({y, dis[y]});
            }
        }
    }
    return cnt == 2;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            G[i].clear();
        }
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(x[j] - x[i] <= d){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }else break;
            }
        }
        ans = 0;
        for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++)
                if(bfs(i, j)) ++ans;
        cout << ans << "\n";
    }
    return 0;
}
