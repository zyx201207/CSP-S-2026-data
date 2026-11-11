#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll c,n,m,d,q;

struct AAA{
    ll v,w;
};
vector<AAA> g[10000005];
ll w[500005];
ll dis[100000005];

ll dijkstra(ll start,ll end){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    repe(i,1,m*n+m+m) dis[i] = 1e18;
    dis[start] = 0;
    pq.push({0,start});
    while(pq.size()){
        auto t = pq.top();pq.pop();
        ll d = t.first,u = t.second;
        if(d > dis[u]) continue;
#ifdef LOCAL
        cout << u << ' ' << d << '\n';
#endif
        if(u == end) return dis[u];
        for(auto i : g[u]){
            #ifdef LOCAL
            cout << "to " << i.v << " for " << i.w << '_';
            #endif
            if(dis[i.v] > d+i.w){
                dis[i.v] = d+i.w;
                pq.push({dis[i.v],i.v});
            #ifdef LOCAL
                cout << "yes\n";
            #endif
            }else{
            #ifdef LOCAL
                cout << "no\n";
            #endif
            }
        }
    }
    return dis[end];
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    repe(i,1,m){
        cin >> w[i];
        g[i].pb({i+m,w[i]});
        g[i+m].pb({i,w[i]});
    }
    repe(i,1,n){
        ll k;
        cin >> k;
        ll u,w1;
        cin >> u >> w1;
        g[u+m].pb({u+m+m*i,w1});
        g[u+m+m*i].pb({u+m,w1});
        repe(j,2,k){
            ll v,w2;
            cin >> v >> w2;
            g[v+m].pb({v+m+m*i,w2});
            g[v+m+m*i].pb({v+m,w2});
            g[u+m*i+m].pb({v+m+m*i,0});
            g[v+m*i+m].pb({u+m+m*i,0});
            u = v;
        }
    }
    #ifdef LOCAL
    repe(i,1,m+m*n){
        if(i <= m){
            cout << "st:";
        }else{
            if(i <= m*2){
               cout << "st hall:";
            }else{
                cout << "line in:";
            }
        }
        cout << i << '\n';
        for(auto j : g[i]){
            cout << "can go to ";
            if(j.v <= m) cout << "st:";
            else if(j.v <= 2*m) cout << "st hall:";
            else cout << "line in:";
            cout << j.v << " for " << j.w << '\n';
        }
    }
    #endif
    while(q--){
        ll x,y;
        cin >> x >> y;
        cout << dijkstra(x,y) << '\n';
    }
    

    return 0;
}