#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc getchar_nolock
#endif
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;

void read(int &x){
    x=0;int f=1;
    char ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=gc();
    }
    x*=f;
}
int c,n,m,d,q;
int door[N],hall[N];
vector<pair<int,int>>rou[N];

struct Edge{
    int to,dis;
    bool operator <(const Edge&x) const{
        return x.dis<dis;
    }
};
vector<Edge> g[N];
priority_queue<Edge> pq;
int f[N],vis[N];

void dijkstra(int s){
    memset(f,0x3f3f3f3f,sizeof f);
    memset(vis,0,sizeof vis);
    f[s]=0;
    pq.push({s,f[s]});
    while(!pq.empty()){
        auto u=pq.top().to;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto e:g[u]){
            int to=e.to;
            if(f[to]>f[u]+e.dis){
                f[to]=f[u]+e.dis;
                pq.push({to,f[to]});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>door[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int u,x;
            cin>>u>>x;
            rou[i].push_back({u,x});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<rou[i].size()-1;j++){
            int u=rou[i][j].first,v=rou[i][j+1].first,w1=rou[i][j].second,w2=rou[i][j+1].second;
            g[u].push_back({v,w1+w2});
            g[v].push_back({u,w1+w2});
            cout<<u<<" "<<v<<" "<<w1+w2<<endl;
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        dijkstra(x);
        cout<<f[y]+door[x]+door[y]<<endl;
    }
    return 0;
}
