#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
using P=pair<ll,int>;
ll w[N];
ll c,n,m,d,q,pre;
ll dist[N];
ll cnt[N];
const ll INF=1e18;
vector<pair<ll,int>>g[N];
ll solve(){
    ll ans=0;
    ll st,ed;
    cin>>st>>ed;
    ans+=w[st];
    ans+=w[ed];
    priority_queue<P,vector<P>,greater<P>>pq;
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    pq.push({0,st});
    dist[st]=0;
    while(pq.size()){
        auto cur=pq.top();
        pq.pop();
        ll d=cur.first;
        int u=cur.second;
        if(d>dist[u]) continue;
        for(auto &edge:g[u]){
            int v=edge.first;
            ll w=edge.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;

            }
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(!cin>>c) return 0;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int i=1;i<=x;i++){
            int u,w;
            cnt[u]++;
            if(i>1){
                g[pre].push_back({u,w});
            }
            pre=u;
        }
    }
    while(q--){
        cout<<solve()<<"\n";
    }
    return 0;
}
