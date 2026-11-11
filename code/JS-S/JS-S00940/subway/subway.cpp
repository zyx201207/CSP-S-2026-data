#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,Q;
const int N=501005;
const ll INF=1e17;
vector<pair<int,ll>> g[N],e[505];
priority_queue<pair<ll,int>> q;
ll dis[505][505],W[N];
void dij(int st){
    for(int i=1;i<=n;i++){
        dis[st][i]=INF;
    }
    dis[st][st]=0;
    q=priority_queue<pair<ll,int>>();
    q.push({0,st});
    while(!q.empty()){
        pair<ll,int> cur=q.top();
        q.pop();
        ll D=cur.first;
        int u=cur.second;
        for(auto i:e[u]){
            ll w=i.second;
            int v=i.first;
            if(w+D<dis[st][v]){
                dis[st][v]=w+D;
                q.push({w+D,v});
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&W[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            ll v;
            scanf("%d%lld",&x,&v);
            g[x].push_back({i,v});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=0;k<j;k++){
                ll w=g[i][j].second+g[i][k].second;
                int p1=g[i][j].first,p2=g[i][k].first;
                e[p1].push_back({p2,w});
                e[p2].push_back({p1,w});
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cerr<<i<<endl;
        for(auto v:e[i]){
            cerr<<v.first<<" "<<v.second<<endl;
        }
    }
    */
    for(int i=1;i<=n;i++){
        dij(i);
        /*
        cout<<i<<" ";
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }cout<<endl;
        */
    }
    for(int i=1;i<=Q;i++){
        int st,ed;
        scanf("%d%d",&st,&ed);
        ll ans=INF;
        for(auto v:g[st]){
            int id1=v.first;
            ll w1=v.second;
            for(auto u:g[ed]){
                int id2=u.first;
                ll w2=u.second;
                /*
                if(i==2&&id1==id2&&id1==1){
                    cout<<ed<<" "<<id2<<" "<<w2<<endl;
                    //cout<<w1<<" "<<w2<<" "<<dis[id1][id2]<<endl;
                }
                */
                ans=min(ans,W[st]+W[ed]+w1+w2+dis[id1][id2]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
