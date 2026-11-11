#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v,u,w,n,m,c,d,q,t,a,k,st,en;
const ll INF=1e17;
struct node{
ll v,w;
};
struct lll{
ll u,w;
bool operator<(const lll &x)const {return x.w < w;}
};
vector<node>G[150000];
vector<ll> Dij(ll st){
priority_queue<lll>Q;
vector<ll>dis(3*m+5,INF);
Q.push({st,0});
dis[st]=0;
while(Q.size()){
    u=Q.top().u;
    Q.pop();
    for(auto e:G[u]){
        v=e.v,w=e.w;
        if(dis[v]>dis[u]+w){
        dis[v]=dis[u]+w;
        Q.push({v,dis[v]});
//        cout << u << "->" << v << ":" << "+" << w << " " << dis[v] << "\n";
        //if(v==en) return dis;
        }
    }
}
return dis;
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cin >> c >> n >> m >> d >> q;
for(int i=1;i<=m;i++){
    cin >> w;
    G[i].push_back({i+m,w});
    G[i+m].push_back({i,w});
}
for(int i=1;i<=n;i++){
    cin >> k;
    for(int j=1;j<=k;j++){
        cin >> a >> t;
        G[a+m].push_back({2*m+i,t});
        G[2*m+i].push_back({a+m,t});
    }
}
while(q--){
    cin >> st >> en;
    auto dis=Dij(st);
    cout << dis[en] << endl;
}
return 0;
}
