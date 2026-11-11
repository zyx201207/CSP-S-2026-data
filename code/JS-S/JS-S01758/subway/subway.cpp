#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;

int c=0,n=0,m=0,d=0,Q=0;
vector<int>w;
struct Mp{
    int v,w;
};
vector<Mp>dik[601];
vector<Mp>fld[1501];
vector<int>BFS[510005];
struct Node{
    int u;
    ll dis;
    bool operator < (const Node& rhs) const {return dis>rhs.dis;}
};
struct FF{
    int t,typ;
};
bool vis[301]={};
ll dis[301]={};
vector<vector<ll>>dp;
vector<vector<FF>>tmp_fld;
bool VIS[510005]={};
int DIS[510005]={};

inline bool chmin(ll& a,const ll b){return a>b?a=b,1:0;}
void dijkstra(int s){
    priority_queue<Node>q;
    fill(dis+1,dis+1+m+n,INF);
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push({s,0ll});
    while(!q.empty()){
        int u=q.top().u;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:dik[u]){
            if(dis[u]+v.w>=dis[v.v]) continue;
            dis[v.v]=dis[u]+v.w;
            q.push({v.v,dis[v.v]});
        }
    }
}
void solve_1_6(){
    for(int i=1;i<=n;++i){
        int k=0,a=0,t=0;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a>>t;
            dik[m+i].push_back({a,t}),dik[a].push_back({m+i,t});
        }
    }
    while(Q--){
        int ss=0,tt=0;
        cin>>ss>>tt;
        dijkstra(ss);
        cout<<1ll*(dis[tt]+w[ss]+w[tt])<<'\n';
    }
}
void solve_A(){
    dp.resize(m+1,vector<ll>(m+1,INF));
    tmp_fld.resize(n+1,vector<FF>(2));
    for(int i=1;i<=n;++i){
        int k=0,a=0,t=0;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a>>t;
            tmp_fld[i].push_back({t,a});
        }
    }
    for(int i=1;i<=m;++i) dp[i][i]=0ll;
    for(int i=1;i<=n;++i){
        if(tmp_fld[i].size()<=1) continue;
        auto a1=tmp_fld[i][0],a2=tmp_fld[i][1];
        dp[a1.typ][a2.typ]=a1.t+a2.t,dp[a2.typ][a1.typ]=a1.t+a2.t;
    }
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                chmin(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(Q--){
        int ss=0,tt=0;
        cin>>ss>>tt;
        cout<<dp[ss][tt]+w[ss]+w[tt]<<'\n';
    }
}
void solve_B(){
    int T=0;
    for(int i=1;i<=n;++i){
        int k=0,a=0,t=0;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a>>t;
            T=t;
            BFS[m+i].push_back(a),BFS[a].push_back(m+i);
        }
    }
    queue<int>q;
    fill(DIS+1,DIS+1+m+n,INF);
    DIS[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(VIS[u]) continue;
        VIS[u]=1;
        for(int v:BFS[u]){
            if(DIS[v]>DIS[u]+1){
                DIS[v]=DIS[u]+1;
                q.push(v);
            }
        }
    }
    while(Q--){
        int ss=0,tt=0;
        cin>>ss>>tt;
        cout<<1ll*(w[ss]+w[tt]+1ll*T*(abs(DIS[ss]-DIS[tt])))+2<<'\n';
    }
}
void solve_22_23(){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    w.resize(m+1);
    for(int i=1;i<=m;++i) cin>>w[i];
    if(1<=c&&c<=6) solve_1_6();
    else if(7<=c&&c<=11) solve_A();//***
    else if(12<=c&&c<=19) solve_B();
    else if(c==22||c==23) solve_22_23();
}