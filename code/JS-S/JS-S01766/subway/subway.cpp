#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<ll,ll> PLL;
ll c,n,m,d,q;
ll w[MAXN],t[MAXN][MAXN];
ll dis[MAXN];
bool vis[MAXN];
vector<ll> st[MAXN];
vector<ll> l[MAXN];
void Dijkstra(ll start);
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in",'r',stdin);
    freopen("subway.out",'w',stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) cin>>w[i];
    for(int i = 1;i <= n;i++){
        ll k;cin>>k;
        for(int j = 1;j <= k;j++){
            ll a;cin>>a;
            st[a].push_back(i);
            l[i].push_back(a);
            cin>>t[i][a];
        }
    }
    while(q--){
        ll s,e;cin>>s>>e;
        Dijkstra(s);
        cout<<dis[e] + w[s] + w[e]<<'\n';
    }
    return 0;
}
void Dijkstra(ll start){
    for(int i = 1;i <= m;i++){
        dis[i] = INF;
        vis[i] = false;
    }
    dis[start] = 0;
    priority_queue<PLL,vector<PLL>,greater<PLL>> heap;
    heap.push({0,start});
    while(!heap.empty()){
        auto tes = heap.top();
        heap.pop();
        ll w = tes.first;
        ll u = tes.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(ll line : st[u]){
            for(ll sta : l[line]){
                if(!vis[sta] && dis[sta] > dis[u] + t[line][u] + t[line][sta]){
                    dis[sta] = dis[u] + t[line][u] + t[line][sta];
                    heap.push({dis[sta],sta});
                }
            }
        }
    }
    return;
}

