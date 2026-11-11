#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;

ll c, n, m, d, q;
ll w[500005];
vector<PLL> dist[10000005];
ll dist2[10000005];
ll road[10000005];
bool vis[10000005];

void Dij(ll x){
    memset(dist2, 0x3f, sizeof(dist2));
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    q.push({0, x});
    dist2[x] = 0;
    ll last = 0;
    while(!q.empty()){
        PLL neww = q.top();
        q.pop();
        ll u = neww.second;
        //cout << u << ' ';
        if(u != last){
            for(PLL i: dist[u]){
                ll v = i.first;
                ll w = i.second;
                if(dist2[v] + w > dist2[u]){
                    dist2[v] = dist2[u] + w;
                    last = u;
                    q.push({dist2[v], v});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    //for(int i = 1; i <= m; i++){
    //    cout << w[i] << ' ';
    //}
    for(int i = 1; i <= n; i++){
        ll k;
        cin >> k;
        ll last;
        cin >> last;
        ll ro;
        cin >> ro;
        //road[last].push_back({i, ro});
        //road[last * 26 + i] = ro;
        dist[last * 26].push_back({last * 26 + i, ro});
        dist[last * 26 + i].push_back({last * 26, ro});
        for(int j = 2; j <= k; j++){
            ll tmp;
            cin >> tmp;
            ll ro2;
            cin >> ro2;
            dist[last * 26 + i].push_back({tmp * 26 + i, 0});
            dist[tmp * 26 + i].push_back({last * 26 + i, 0});
            dist[tmp * 26].push_back({tmp * 26 + i, ro2});
            dist[tmp * 26 + i].push_back({tmp * 26, ro2});
        }
    }
    //for(int i = 1; i <= m; i++){
    //    for(PLL j : dist[i * 26]){
    //        cout << j.first << ' ' << j.second  << ' ' ;
    //    }
    //    cout << endl;
    //}
    for(int i = 1; i <= q; i++){
        ll x, y;
        cin >> x >> y;
        Dij(x * 26);
        cout << w[x] + w[y] + dist2[y * 26] << endl;
    }
    return 0;
}
