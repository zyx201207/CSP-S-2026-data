#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
int c, T;
int n; ll d;
ll x[N];
bool e[N][N];
ll dis[N];
int dp[N];
bool vis[N];
ll lllabs(ll x){ return (x > 0 ? x : -x); }
void bfs(int st){
    for(int i = 1; i <= n; i++) dis[i] = 1e9, dp[i] = 1;
    for(int i = 1; i <= n; i++) vis[i] = false;
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v = u + 1; v <= n; v++){
            if(!e[u][v]) break;
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                dp[v] = 1;
                q.push(v);
            }else if(dis[v] == dis[u] + 1){
                dp[v]++;
                q.push(v);
            }
        }
    }
}
void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << e[i][j] << ' ';
         }
         cout << '\n';
    }
}
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            e[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(lllabs(x[i] - x[j]) > d) continue;
            e[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        bfs(i);
        for(int j = i + 1; j <= n; j++){
            if(dp[j] == 2){
                    ans++;
                //cerr << i << ' ' << j << '\n';
            }
            //if(i <= 4 && j == 8) cout << "\ndddd " << dp[j] << '\n';
        }
    }
    //print();
    cout << ans << '\n';
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--) solve();
    return 0;
}

