#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long

const int MAXM=2e4+10;
int w[MAXM];
int c,n,m,d,q;

int tot;
vector<pii> g[MAXM*45];

int dis[MAXM],st[MAXM];
int dij(int s,int f){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii> >pq;

    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second; pq.pop();
        if(st[u]) continue;
        st[u]=1;
        for(auto edge:g[u]){
            int v=edge.first,w=edge.second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    return dis[f];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    tot=m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            ++tot;
            g[x].push_back({tot,t});
            g[tot].push_back({x,t});
            if(j>1){
                g[tot-1].push_back({tot,0});
                g[tot].push_back({tot-1,0});
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dij(x,y)<<"\n";
    }

    return 0;
}
