#include <bits/stdc++.h>
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pdd;

const ll inf=1145141145141919810;
const int _=500502;

struct Edge{
    int to;
    ll w;
    bool operator==(const Edge&rhs)const{
        return to==rhs.to&&w==rhs.w;
    }
};
struct query{
    int id,u,v;
    bool operator<(const query&rhs)const{
        return u<rhs.u;
    }
}Q[100005];
ll ans[100005];
int c,n,m,d,q; //c测试点 n列车总数 m站台总数 d最大度数 q询问个数
ll w[_]; //w[i]进出站台i的时间
vector<Edge> g[_]; //邻接表
ll dist[_];
ll dist2[_];
struct cmp{
    bool operator()(int u,int v)const{
        return dist[u]>dist[v];
    }
};
priority_queue<int,vector<int>,cmp> pq;
bool vis[_];
void dij(int u){
    for (int i=1;i<=m+n;i++){
        dist[i]=inf;
        vis[i]=0;
    }
    dist[u]=0;
    pq.push(u);
    int now;
    while (!pq.empty()){
        now=pq.top();
        pq.pop();
        vis[now]=1;
        for (Edge e:g[now]){
            if (!vis[e.to]){
                dist[e.to]=min(dist[e.to],dist[now]+e.w);
                pq.push(e.to);
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    int k,a;
    ll t;
    //n==1
    if (n==1){
        cin>>k;
        for (int i=1;i<=k;i++){
            cin>>a>>t;
            dist[a]=t;
        }
        int u,v;
        for (int i=1;i<=q;i++){
            cin>>u>>v;
            cout<<dist[u]+dist[v]+w[u]+w[v]<<'\n';
        }
        return 0;
    }
    //n==2
    if (n==2){
        ll best=inf;
        cin>>k;
        for (int i=1;i<=k;i++){
            cin>>a>>t;
            dist[a]=t;
        }
        cin>>k;
        for (int i=1;i<=k;i++){
            cin>>a>>t;
            dist2[a]=t;
            if (dist[a]!=0){
                best=min(best,dist[a]+t);
            }
        }
        int u,v;
        ll res=inf;
        bool ua,ub,va,vb;
        for (int i=1;i<=q;i++){
            res=inf;
            cin>>u>>v;
            //a:第一列 b:第二列
            ua=(dist[u]!=0);
            ub=(dist2[u]!=0);
            va=(dist[v]!=0);
            vb=(dist2[v]!=0);
            if (ua&va) res=min(res,dist[u]+dist[v]);
            if (ub&vb) res=min(res,dist2[u]+dist2[v]);
            if (ua&vb) res=min(res,dist[u]+dist2[v]+best);
            if (ub&va) res=min(res,dist2[u]+dist[v]+best);
            cout<<res+w[u]+w[v]<<'\n';
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        cin>>k;
        for (int j=1;j<=k;j++){
            cin>>a>>t;
            g[m+i].pb(Edge{a,t});
            g[a].pb(Edge{m+i,t});
        }
    }
    int u,v;
    for (int i=1;i<=q;i++){
        cin>>u>>v;
        if (u>v) swap(u,v);
        Q[i]=query{i,u,v};
    }
    sort(Q+1,Q+q+1,less<query>());
    int curu=0;
    for (int i=1;i<=q;i++){
        if (Q[i].u!=curu){
            curu=Q[i].u;
            dij(curu);
        }
        ans[Q[i].id]=dist[Q[i].v]+w[Q[i].u]+w[Q[i].v];
    }
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
