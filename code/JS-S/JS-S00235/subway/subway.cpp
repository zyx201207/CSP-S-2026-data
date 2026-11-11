#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using P=pair<ll,int>;
const int N=5e5+5;
const ll INF=1e18;

int c,n,m,d,q;
int w[N];
ll dis[N];
int t[505][N];

vector<pair<int,ll>> g[N];
int summ;
priority_queue<P,vector<P>,greater<P>> pq;
void dijsktra(int start_node){
    for(int i=1;i<=summ;i++){
        dis[i]=INF;
    }
    dis[start_node]=0;
    pq.push({0,start_node});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(dis[u] < d) continue;

        for(auto ed:g[u]){
            auto [v,w]=ed;


            if(dis[u]+w < dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}



int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        summ+=k;

        int u,tu;
        cin>>u>>t[i][1];
        tu=t[i][1];
        for(int j=2;j<=k;j++){
            int v;
            cin>>v>>t[i][j];

            g[u].push_back({v,t[i][j]+tu});
            g[v].push_back({u,t[i][j]+tu});
            u=v;
            tu=t[i][j];
        }
    }

    while(q--){
        int s,e;
        cin>>s>>e;
        dijsktra(s);
        ll ans=dis[e]+w[s]+w[e];
        cout<<ans<<endl;
    }
    return 0;
}

