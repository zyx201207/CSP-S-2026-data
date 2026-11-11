#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e3 + 9;

ll c, T, a[N], sum, dist[N][N], s[N][N], n, d;

vector<int> g[N];

void bfs(int x){
    for(int i = 1; i <= n; i++){
        dist[x][i] = 0;
    }
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dist[x][v] != 0){
                if(dist[x][v] > dist[x][u] + 1){
                    dist[x][v] = dist[x][u] + 1;
                    s[x][v] = 1;
                } else if(dist[x][v] == dist[x][u] + 1){
                    s[x][v]++;
                } else{
                    continue;
                }
            } else{
                dist[x][v] = dist[x][u] + 1;
                s[x][v] = 1;
            }
            q.push(v);
        }
    }
}

void solve(){
    sum = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        g[i].clear();
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            dist[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[j] - a[i] <= d){
                g[i].push_back(j);
            }
        }
    }
    for(int i = 1; i < n; i++){
        bfs(i);
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(s[i][j] == 2){
                sum++;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T--){
        solve();
        cout << sum << '\n';
    }
    return 0;
}
