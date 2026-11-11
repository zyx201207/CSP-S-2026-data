#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int mxm = 5e5 + 5 , mx = 1e6 + 5;
int c , n , m , d , q , k[mxm];
ll WW[mxm]; vector<vector<ll>> t; vector<vector<int>> a;
struct Edge{
    int v; ll val;
}; vector<Edge> edge[mx];
int main(){
    freopen("subway.in" , "r" , stdin); freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q; a.resize(n + 1 , vector<int>()); t.resize(n + 1 , vector<ll>());
    for(int i = 1 ; i <= m ; i++){ cin >> WW[i]; edge[i].push_back({i + m , WW[i]}); edge[i + m].push_back({i , WW[i]}); }
    int tot = m + m;
    for(int i = 1 ; i <= n ; i++){ 
        cin >> k[i]; a[i].resize(k[i] + 1); t[i].resize(k[i] + 1); 
        for(int j = 1 ; j <= k[i] ; j++){
            cin >> a[i][j] >> t[i][j];
            edge[a[i][j] + m].push_back({++tot , t[i][j]});
            edge[tot].push_back({a[i][j] + m , t[i][j]});
            if(j == 1){ continue; }
            edge[tot - 1].push_back({tot , 0});
            edge[tot].push_back({tot - 1 , 0});
        }
    } 
    for(int i = 1 ; i <= q ; i++){
        int st , ed; cin >> st >> ed;
        vector<ll> dist(mx , inf);
        dist[st] = 0; priority_queue<pair<ll , int>> pq;
        pq.push({0 , st});
        while(!pq.empty()){
            int u = pq.top().second; ll d = -pq.top().first; pq.pop();
            if(d > dist[u]){ continue; }
            for(Edge ed : edge[u]){ 
                int v = ed.v , w = ed.val;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({-dist[v] , v});
                } 
            }
        }
        cout << dist[ed] << "\n";
    }
    return 0;
}