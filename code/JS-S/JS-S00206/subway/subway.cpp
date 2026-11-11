#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int M=500010;
const int Q=100010;
int c,n,m,d,q,k,cnt,tot,head[M];
int dist[M],w[M],a[N][21],t[N][21],x[Q],y[Q],ans[Q];

struct Edge{
    int to,nxt,val;
}e[M];

struct Node{
    int u,d;
    bool operator<(const Node& other)const{
        return d>other.d;
    }
}no[M];

priority_queue<Node> pq;

void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].val=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

void dijkstra1(int st,int en){
    while(!pq.empty()){
        pq.pop();
    }
    for(int i=1;i<=n;i++){
        dist[i]=1e9;
    }
    pq.push({st,0});
    dist[st]=0;
    while(!pq.empty()){
        int u=pq.top().u;
        int d=pq.top().d;
        pq.pop();
        if(dist[u]>d){
            continue;
        }
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].val;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({v,dist[v]});
                if(v==en){
                    ans[++tot]=dist[en];
                    break;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }

    if(7<=c&&c<=11){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k-1;j++){
                add(a[i][j],a[i][j+1],t[i][j]+t[i][j+1]);
            }
        }
        for(int i=1;i<=q;i++){
            dijkstra1(x[i],y[i]);
            ans[i]+=w[x[i]]+w[y[i]];
        }
        for(int i=1;i<=q;i++){
            cout<<ans[i]<<"\n";
        }
    }

    return 0;
}
