#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510];
long long w[500010],dist[500010];
bool vis[500010];
vector<int>a[510];
vector<long long>t[510];
vector<pair<int,long long>>vec[500010];
struct dre{
    long long ans;
    int st;
};
priority_queue<pair<long long,int>>p;
void dijkstra(int x){
    dist[x]=0;
    p.push({0,x});
    while(!p.empty()){
        auto t1=p.top();
        p.pop();
        int u=t1.second;
        if(vis[u]) continue;
        vis[u]=true;
        for(auto ed:vec[u]){
            int v=ed.first,cnt=ed.second;
            if(dist[v]>dist[u]+cnt){
                dist[v]=dist[u]+cnt;
                p.push({-dist[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    bool c=true;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>2) c=false;
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=0;j<k[i];j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    if(c){
        for(int i=1;i<=n;i++){
            int x=t[i][1]+t[i][2];
            vec[a[i][1]].push_back({a[i][2],x});
            vec[a[i][2]].push_back({a[i][1],x});
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            for(int i=0;i<=m;i++){
                dist[i]=1e18;
                vis[i]=false;
            }
            dijkstra(x);
            cout<<w[x]+dist[y]+w[y]<<'\n';
        }
    }
    else{
        for(int i=1;i<=n;i++){
            vec[i*m+a[i][1]].push_back({a[i][1],t[i][1]});
            vec[a[i][1]].push_back({i*m+a[i][1],t[i][1]});
            for(int j=2;j<=k[i];j++){
                vec[i*m+a[i][j]].push_back({a[i][j],t[i][j]});
                vec[a[i][j]].push_back({i*m+a[i][j],t[i][j]});
                vec[i*m+a[i][j]].push_back({i*m+a[i][j-1],0});
                vec[i*m+a[i][j-1]].push_back({i*m+a[i][j],0});
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            for(int i=0;i<=(n+1)*m;i++){
                dist[i]=1e18;
                vis[i]=false;
            }
            dijkstra(x);
            cout<<w[x]+dist[y]+w[y]<<'\n';
        }
    }
    return 0;
}
