#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;//125750
ll w[500];
ll dis[126000];
struct Node{
    ll d,v;
    bool operator>(const Node &aa) const {return v > aa.v;}
};
vector <Node> p[126000];
priority_queue <Node,vector<Node>,greater<Node>> pq;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;++i) cin>>w[i];
    for(int i = 1;i <= n;++i){
        ll k;
        cin>>k;
        for(int j = 1;j <= k;++j){
            ll ii,jj;
            cin>>ii>>jj;
            p[i+m].push_back({ii,jj});
            p[ii].push_back({i+m,jj});
        }
    }
 //   for(int i = 1;i <= n+m;++i){
 //       cout<<i<<"i:";
 //       for(auto u:p[i]){
 //           cout<<u.v<<" ";
 //       }
 //       cout<<endl;
 //   }
    while(q--){
        bool b[n+m+2]={};
        fill((ll*)dis,(ll*)dis+n+m+2,INF);
        while(!pq.empty()) pq.pop();
        int x,y;
        cin>>x>>y;
        dis[x] = 0;
        pq.push({x,dis[x]});
        while(!pq.empty()){
            ll e = pq.top().d;
            if(e == y) break;
            b[e] = true;
            pq.pop();
            for(auto o:p[e]){
                if(!b[o.d]){
                    dis[o.d] = min(dis[o.d],dis[e]+o.v);
                    pq.push({o.d,dis[o.d]});
                }
            }
        }
        cout<<dis[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
