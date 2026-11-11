#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll INF=114514'1919'810'000'00;


ll c,n,m,d,q;// c and d is useless,n is num of line,s is num of station;
vector<ll> to_zt;
vector<ll> line_st_sum; 
vector<vector<ll>> line_cr_st;
vector<vector<ll>> zt_to_line_t;
vector<pll> adj_cost;

void clear_and_start(){
    to_zt.assign(m+1,0);
    line_st_sum.assign(n+1,0);
    line_cr_st.assign(n+1,vector<ll>());
    zt_to_line_t.assign(n+1,vector<ll>());
    adj_cost.assign(m+1,pll());
    for(int i=0;i<m;i++){
        cin>>to_zt[i];
    }
    for(int i=0;i<n;i++){
        cin>>line_st_sum[i];
        zt_to_line_t[i].assign(m+1,0);
        for(int j=0;j<line_st_sum[i];j++){
            ll u,t;
            cin>>u>>t;
            line_cr_st[i].push_back(u);
            zt_to_line_t[i][u]=t;
        }
    }
    for(int i=0;i<n;i++){
        for(auto st_u:line_cr_st[i]){
            for(auto st_v:line_cr_st[i]){
                ll tmp=zt_to_line_t[i][st_u]+zt_to_line_t[i][st_v];
                adj_cost[st_u].first=tmp;
                adj_cost[st_v].second=st_v;
            }
        }
    }
};

ll dij(ll x,ll y){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> dis(m+1,INF);
    vector<bool> vis(m+1,false);
    pq.push(adj_cost[x]);
    vis[x]=true;
    while(!pq.empty()){
        pll tmp=pq.top();
        ll w=tmp.first;
        ll v=tmp.second;
        vis[v]=true;
        for(auto &e:adj_cost){
            ll n_w=e.first;
            ll n_v=e.second;
            if(dis[v]>dis[v]+n_w){dis[n_v]=dis[w]+n_v;}
        }
    }
    return dis[y];   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    clear_and_start();
    while(q--){
        ll x,y;
        cin>>x>>y;
        x-=1;y-=1;// get the real id
        cout<<dij(x,y)<<'\n';
    }
    return 0;
}