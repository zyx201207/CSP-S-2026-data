#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 1005 ;
struct node{
    ll v , w ;
    bool operator<(const node &t) const{
        return t.w<w ;
    }
};
ll c , n , m , d , q , i , j , x , y , w[MAXN] , dis[MAXN*2] , vis[MAXN*2] , k[MAXN] , D[MAXN][MAXN] , a[505][MAXN] , t[505][MAXN] ;
vector<node> v[MAXN*2] ;
void dijkstra(ll x){
    memset(dis,0x3f,sizeof(dis)) ;
    memset(vis,false,sizeof(vis)) ;
    priority_queue<node> q ;
    q.push({x,0}) ;
    dis[x] = 0 ;
    while(!q.empty()){
        ll u = q.top().v ;
        q.pop() ;
        if(vis[u]){
            continue ;
        }
        vis[u] = true ;
        for(auto &&k : v[u]){
            ll v = k.v , w = k.w ;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w ;
                q.push({v,dis[v]}) ;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        D[x][i] = dis[i] ;
    }
}
int main(){
    freopen("subway.in","r",stdin) ;
    freopen("subway.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> c >> n >> m >> d >> q ;
    for(i=1;i<=m;i++){
        cin >> w[i] ;
    }
    for(i=1;i<=n;i++){
        cin >> k[i] ;
        for(j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j] ;
            v[a[i][j]].push_back({i+m,t[i][j]}) ;
            v[i+m].push_back({a[i][j],t[i][j]}) ;
        }
    }
    for(i=1;i<=m;i++){
        dijkstra(i) ;
    }
    while(q--){
        cin  >> x >> y ;
        cout << D[x][y]+w[x]+w[y] << '\n' ;
    }
    return 0 ;
}
