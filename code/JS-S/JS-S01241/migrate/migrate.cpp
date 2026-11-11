#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;/*
ll bfs(ll x,vector<vector<ll>>& tu,ll n){
    vector <ll> dis(n + 5,1e18);
    vector<vector<bool>> vis(n + 5,vector<bool>(n + 5,false));
    queue <ll> q;
    dis[1] = 0;
    q.push(1);
    ll cnt= 0;
    while (!q.empty()){
        ll u = q.front();q.pop();
        for (auto v : tu[u]){
            if (dis[v] != 1e18 && vis[u][v]){
                if (dis[v] == dis[u] + 1){
                    cnt++;
                    //cout << u << ' ' << v << "\n";
                    vis[u][v] = false;
                }
            }
            else{
                dis[v] = dis[u] + 1;
                vis[u][v] = true;
                q.push(v);
            }
        }
    }return cnt;
}*/
ll flo(vector<vector<ll>>& tu,ll n){
    vector<vector<ll>> dis(n + 5,vector<ll>(n + 5,1e18));
    vector<vector<re>> vis(n + 5,vector<re>(n + 5,0));
    for (re i = 1;i <= n;i++){
        for (auto j : tu[i]) dis[i][j] = 1;
    }
    for (re i = 1;i <= n;i++){
        for (re k = 1;k <= n;k++){
            if (i == k || dis[i][k] == 1e18) continue;
            for (re j = 1;j <= n;j++){
                if (i == j || j == k || dis[k][j] == 1e18) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    vis[i][j] = 1;
                }
                else if (dis[i][j] == dis[i][k] + dis[k][j] && vis[i][j] == 1){
                    vis[i][j] = 2;
                }
            }
        }
    }
    ll cnt = 0;
    for (re i = 1;i <= n;i++) for (re j = 1;j <= n;j++) if (vis[i][j] == 2) cnt++;
    return cnt;
}
void sol(){
    ll n,d;cin >> n >> d;
    vector <ll> x(n + 5);
    vector <vector<ll>> tu(n + 5);
    for (re i = 1;i <= n;i++) cin >> x[i];
    for (re i = 1;i <= n;i++){
        for (re j = i + 1;j <= n;j++){
            if (x[j] - x[i] > d){
                break;
            }
            tu[i].push_back(j);
        }
    }
    ll cnt = 0;
    cnt += flo(tu,n);
    //for (re i = 1;i <= n;i++) cnt += bfs(i,tu,n);
    cout <<cnt << "\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    re c,t;cin >> c >> t;
    while (t--) sol();
    return 0;
}
