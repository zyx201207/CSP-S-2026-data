#include<bits/stdc++.h>
typedef long long ll;
#define int long long
using namespace std;
const int N=600005;
struct node{
    int v;
    ll w;
};
ll w[N];
vector<node>g[N];
ll d[N];
set<pair<ll,int>>s;
void dijkstra(ll t){
    memset(d,0x3f,sizeof d);
    d[t]=0;
    s.insert({0,t});
    while(!s.empty()){
        int u=s.begin()->second;
        s.erase(s.begin());
        for(auto i:g[u]){
            int v=i.v,w=i.w;
            if(d[v]>d[u]+w){
                //if(v==3){
                 //   cout<<u<<endl;
                //    cout<<d[u]<<endl;
                //    cout<<w<<endl;
                //    cout<<"00000000000"<<endl;
                //}
                s.erase({d[v],v});
                d[v]=d[u]+w;
                s.insert({d[v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,dd,q;
    cin>>c>>n>>m>>dd>>q;int tot=m;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        tot++;
        for(int j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            g[a].push_back({tot,t});
            g[tot].push_back({a,t});
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<d[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
