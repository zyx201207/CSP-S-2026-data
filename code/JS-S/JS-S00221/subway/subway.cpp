#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5,maxm=505;
const ll INF=1e18;
int c,n,m,d,p;
ll w[maxn],k[maxn],e[510][510],ans;
int t[maxm][maxn];
vector<int> T[maxn];
struct node{
    int v;
    ll w;
    bool operator <(const node& other) const{
        return w<other.w;
    }
};
vector<node> G[510];
ll dis[510],inq[510];
priority_queue <node,vector<node> > q;
void init(){
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        dis[i]=INF;
        inq[i]=0;
    }
}
void dij(int x){
    q.push((node){x,0});
    inq[x]=1;
    dis[x]=0;
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        for(auto x:G[u]){
            int v=x.v;
            ll w=x.w;
            if(dis[v]>=dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    q.push((node){v,dis[v]});
                    inq[v]=1;
                }
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
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int X;
        for(int j=1;j<=k[i];j++){
            cin>>X>>t[i][X];
            T[X].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            e[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto u:T[i]){
            for(auto v:T[i]){
                if(u==v)continue;
                e[u][v]=min(e[u][v],1LL*t[u][i]+1LL*t[v][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(e[i][j]==INF)continue;
            G[i].push_back((node){j,e[i][j]});
        }
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        ans=INF;
        for(auto u:T[x]){
            init();
            dij(u);
            ll tmp=w[x]+1LL*t[u][x],ansl=INF;
            for(auto v:T[y]){
                ansl=min(ansl,tmp+dis[v]+w[y]+1LL*t[v][y]);
            }
            ans=min(ans,ansl);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
