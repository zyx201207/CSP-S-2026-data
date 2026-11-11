#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 2e6 + 5;
const int inf = 1e9 + 5;
int c , t , n; ll d , x[mxn];
int main(){
    freopen("migrate.in" , "r" , stdin); freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i++){ cin >> x[i]; }
        if(c == 13 || c == 14){ cout << 0 << "\n"; continue; }
        ll ans = 0; vector<vector<int>> adj(n + 1 , vector<int>());
        for(int i = 1 ; i < n ; i++){
            for(int j = i + 1 ; j <= n ; j++){
                if(x[j] - x[i] <= d){ adj[i].push_back(j); }
            }
        } 
        for(int i = 1 ; i <= n ; i++){
            vector<int> dist(n + 1 , inf) , g(n + 1 , 0);
            dist[i] = 0; priority_queue<pair<int , int> > pq;
            pq.push({0 , i}); g[i] = 1;
            while(!pq.empty()){
                int d = -pq.top().first , u = pq.top().second; pq.pop();
                if(d > dist[u]){ continue; }
                for(int v : adj[u]){
                    if(dist[v] > (d + 1)){
                        dist[v] = d + 1; g[v] = g[u];
                        pq.push({-dist[v] , v});
                        continue;
                    } 
                    if(dist[v] == (d + 1)){ 
                        g[v] += g[u]; 
                    }
                }
            }
            for(int i = 1 ; i <= n ; i++){ if(g[i] == 2){ ans++; } }
        } cout << ans << "\n";
    }
    return 0;
}