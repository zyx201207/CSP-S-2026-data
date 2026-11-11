#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N =5e5+10;
struct node{
    int no,w;
};
vector<node>g[N];
priority_queue< PII,vector<PII>,greater<PII> >pq;
ll dis[N];
void dij(int x){
    memset(dis,0x3f,sizeof dis);
    dis[x] = 0;
    pq.push({0,x});
    while(pq.size()){
        auto [d,u] = pq.top();
        if(d>dis[u])continue;
        for(auto [v,w]:g[u]){
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
int main (){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        int w;
        cin >> w;
        g[i].push_back({i,w});
    }
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int x,tmp;
            cin >> x>>tmp;
            g[x][0].w += tmp;
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        dij(x);
        cout << dis[y]<<'\n';
    }
    return 0;
}
