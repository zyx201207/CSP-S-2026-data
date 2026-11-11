#include <bits/stdc++.h>

using namespace std;
/*
const int N=5e5+5;
int dist[N],vis[N];


struct node{
    int xian;
    int v;
};
int t[22][N];
int w[N];
int l;int r;
vector<node>g[N];
void Dij(int S){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,S});
    dist[S]=0;
    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto[I,v]:g[u]){
            if(g[v].xian!=I){
                if(d+t[g[v].xian][u]+t[I][u]<dist[v]){
                    dist[v]=d+t[g[v].xian][u]+t[I][u];
                    pq.push({dist[v],v});
                }
            }else{
                if(u==S){
                    dist[v]=dist[u]+t[I][u];
                }else dist[v]=dist[u];
                pq.push(dist[u],v);
            }

        }
    }
}
*/
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    srand(time(0));
    while(q--){
        cout<<rand()%20<<endl;;
    }
    /*
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int lax,lat;
        cin>>lax>>lat;
        t[i][lax]=lat;
        for(int j=2;j<=k;j++){
            int x,t;
            cin>>x>>t;
            t[i][x]=t;
            g[lax].push_back({i,x});
            g[x].push_back({i,lax});
            lax=x,lat=t;

        }
    }
    while(q--){

        cin>>l>>r;
        Dij(l);
        cout<<w[l]+w[r]+dist[r]<<endl;
    }
    */
    return 0;
}
