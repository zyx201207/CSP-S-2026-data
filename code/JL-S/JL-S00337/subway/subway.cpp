#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

const ll N=5e6+7,M=5e2+7,K=5e5+7,inf=1e18;

ll idx;
vector<PII>g[N];

ll c,n,m,d,q;

ll w[K],k[K];

ll trans(ll x,ll tp,ll xid){
    if(tp==1) return x;
    if(tp==2) return x+K;
    if(tp==3) return x+2*K+xid*M;
    return -1;
}

void add(ll u,ll v,ll w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

vector<ll>dis;

vector<ll> dijkstra(ll s){
    vector<ll>dist(N+1,inf);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    dist[s]=0;
    q.push({0,s});
    while(!q.empty()){
        PII u0=q.top();
        q.pop();
        ll d=u0.first,u=u0.second;
        //cout<<d<<" "<<u<<endl;
        for(PII v0:g[u]){
            ll v=v0.first,w=v0.second;
            //cout<<"u:"<<u<<" "<<" "<<v<<" "<<w<<endl;
            //cout<<"d"<<dist[v]<<" "<<dist[u]+w<<endl;
            if(dist[v]>dist[u]+w){
                    //cout<<"YES!!!"<<dist[v]<<" "<<dist[u]+w<<endl;
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        add(trans(i,1,0),trans(i,2,0),w[i]);
        //cout<<"kkk"<<trans(i,1,0)<<" "<<trans(i,2,0)<<endl;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        ll lsta=-1;
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            if(j!=1){
                add(trans(lsta,3,i),trans(a,3,i),0);
                //cout<<"ppp"<<trans(lsta,3,i)<<" "<<trans(a,3,i)<<endl;
            }
            add(trans(a,2,0),trans(a,3,i),t);
            //cout<<"sss"<<trans(lsta,2,0)<<" "<<trans(a,3,i)<<endl;
            lsta=a;
        }
    }
    for(int i=1;i<=q;i++){
        ll u,v;
        cin>>u>>v;
        dis=dijkstra(trans(u,1,0));
        cout<<dis[trans(v,1,0)]<<'\n';
    }
    return 0;
}

