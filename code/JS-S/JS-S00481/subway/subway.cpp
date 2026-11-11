#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
int ccc,n,m,d,q,edgeCnt;
int w[405],k[205],a[205][405],t[205][405];

int head[80405],nxt[320805],to[320805],weight[320805];
void addEdge(int u,int v,int w){
    nxt[++edgeCnt] = head[u];
    head[u] = edgeCnt;
    to[edgeCnt] = v;
    weight[edgeCnt] = w;
}

void buildGragh(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int jj=1;jj<j;jj++){
                addEdge(i*m+a[i][jj],i*m+a[i][j],0);
                addEdge(i*m+a[i][j],i*m+a[i][jj],0);
            }
            addEdge(0*m+a[i][j],i*m+a[i][j],t[i][j]);
            addEdge(i*m+a[i][j],0*m+a[i][j],t[i][j]);
        }
    }
}

struct node{
    int v,w;
    bool operator<(const node &t)const{
        return w > t.w;
    }
};

int st,ed;
int dist[80405];
void dijkstra(){
    for(int i=1;i<=m*(n+1);i++){
        dist[i] = inf;
    }
    dist[st] = 0;
    priority_queue<node> pq;
    pq.push({st,0});
    while(pq.size()){
        if(dist[pq.top().v]<pq.top().w){
            pq.pop();
            continue;
        }
        int u = pq.top().v;
        for(int ei=head[u];ei;ei=nxt[ei]){
            if(dist[to[ei]]>dist[u]+weight[ei]){
                dist[to[ei]] = dist[u] + weight[ei];
                pq.push({to[ei],dist[to[ei]]});
            }
        }
        pq.pop();
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>ccc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    buildGragh();
    while(q--){
        cin>>st>>ed;
        dijkstra();
        cout<<dist[ed]+w[st]+w[ed]<<'\n';
    }
    return 0;
}