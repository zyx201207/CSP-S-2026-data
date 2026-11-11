#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define OK cout<<"OK\n"
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C,n,m,d,q;
    cin>>C>>n>>m>>d>>q;
    vector<ll> w(m+1);
    vector<vector<int>> line(m+1);
    vector<vector<pair<int,ll>>> e(m+n+5);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,u,w;j<=k;j++){
            cin>>u>>w;
            line[u].push_back(i);
            e[m+i].push_back({u,w});
            e[u].push_back({m+i,w});
        }
    }
    if(16<=C&&C<=19){
        queue<int> pq;
        vector<vector<ll>> dis(n+1,vector<ll>(m+n+5,LLONG_MAX/2));
        auto dij=[&](int i){
            dis[i][m+i]=0;
            pq.push(m+i);
            while(!pq.empty()){
                auto u=pq.front();
                pq.pop();
                for(auto [v,w]:e[u]){
                    if(dis[i][u]+w<dis[i][v]){
                        dis[i][v]=dis[i][u]+w;
                        pq.push(v);
                    }
                }
            }
        };
        while(q--){
            int x,y;
            cin>>x>>y;
            ll ans=LLONG_MAX/2;
            for(auto i:line[x]){
                if(dis[i][m+i]) dij(i);
                ans=min(ans,dis[i][x]+dis[i][y]);
            }
            cout<<ans+w[x]+w[y]<<'\n';
        }
        return 0;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<vector<ll>> dis(n+1,vector<ll>(m+n+5,LLONG_MAX/2));
    auto dij=[&](int i){
        dis[i][m+i]=0;
        pq.push({0,m+i});
        while(!pq.empty()){
            auto u=pq.top().second;
            pq.pop();
            for(auto [v,w]:e[u]){
                if(dis[i][u]+w<dis[i][v]){
                    dis[i][v]=dis[i][u]+w;
                    pq.push({dis[i][v],v});
                }
            }
        }
    };
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=LLONG_MAX/2;
        for(auto i:line[x]){
            if(dis[i][m+i]) dij(i);
            ans=min(ans,dis[i][x]+dis[i][y]);
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}