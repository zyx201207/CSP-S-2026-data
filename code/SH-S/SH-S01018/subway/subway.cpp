#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e2+9;
const int N=5e5+9;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll a[N];
int x[N],y[N],f[N];
bool e[M][M];
struct Node{
    int v;
    ll w;
    bool operator<(const Node X)const{
        return w<X.w;
    }
};
vector<Node>lin[N],g[M];
inline void add(int u,int v,ll w){
    g[u].push_back((Node){v,w});
    g[v].push_back((Node){u,w});
}
ll dis[M][M],vis[M];
int main(){
    freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    // cout<<"start\n";
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",a+i);
    for(int i=1,k;i<=n;i++){
        scanf("%d",&k);
        ll t;
        for(int j=1;j<=k;j++){
            scanf("%d",x+j);
            scanf("%lld",&t);
            for(auto nxt:lin[x[j]])
                add(i,nxt.v,t+nxt.w);
            lin[x[j]].push_back((Node){i,t});
        }
    }
    for(int i=1,j;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        for(int k=0;k<g[i].size();k++){
            j=g[i][k].v;
            if(dis[i][j])g[i].erase(g[i].begin()+k),k--;
            else dis[i][j]=1;
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",x+i,y+i);
        for(auto nxt:lin[x[i]])
            for(auto frm:lin[y[i]])
                if(!e[nxt.v][frm.v])
                    e[nxt.v][frm.v]=1,f[nxt.v]++;
    }
    for(int i=1;i<=n;i++){
        if(!f[i])continue;
        for(int j=1;j<=n;j++)
            dis[i][j]=INF,vis[j]=0;
        priority_queue<Node>p;
        p.push({i,0}),dis[i][i]=0;
        while(!p.empty()){
            int u=p.top().v;p.pop();
            if(vis[u])continue;
            if(e[i][u])f[i]--;
            if(!f[i])break;
            vis[u]=1;
            int v;ll w;
            for(auto nxt:g[u]){
                v=nxt.v,w=nxt.w;
                if(dis[i][u]+w<dis[i][v])
                    dis[i][v]=dis[i][u]+w,p.push({v,-dis[i][v]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll ans=INF;
        for(auto frm:lin[x[i]])
            for(auto nxt:lin[y[i]]){
                ans=min(ans,dis[frm.v][nxt.v]+frm.w+nxt.w);
                // cout<<frm.v<<" "<<nxt.v<<" "<<frm.w<<" "<<nxt.w<<" "<<dis[frm.v][nxt.v]<<endl;
            }
        printf("%lld\n",ans+a[x[i]]+a[y[i]]);
    }
    // cout<<"end\n";
    return 0;
}
