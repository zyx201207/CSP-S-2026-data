#include<bits/stdc++.h>
using namespace std;

struct state{
    int u,dist,ln;
};

const int MAXM=5e5+5;
const int MAXD=22;
const int INF=0x3f3f3f3f;
int c,n,m,d,q,ans;
int idx;
int w[MAXM];
int chg[MAXM][MAXD],vis[MAXM][MAXD][MAXD];
int dis[MAXM],dfn[MAXM],id[MAXM];
vector<vector<int> >g;

void dij(int st,int ed){
    queue<state>q;
    int mindis=INF,lin;
    for(int i=1;i<=n;i++){
        if(!chg[st][i]) continue;
        if(chg[st][i]<mindis){
            lin=i;
            mindis=chg[st][i];
        }
    }
    dis[st]=w[st]+mindis;
    q.push({dfn[st],dis[st],lin});
    while(!q.empty()){
        auto cur=q.front();q.pop();
        int dfnu=cur.u;
        int d=cur.dist;
        int l=cur.ln;
        if(id[dfnu]==ed){
            ans=min(ans,d+w[id[dfnu]]+chg[id[dfnu]][l]);
            continue;
        }
        if(d>dis[dfnu]) continue;
        for(int dfnv:g[dfnu]){
            if(d<dis[dfnv]){
                dis[dfnv]=d;
                q.push({dfnv,dis[dfnv],l});
            }
        }
        for(int i=1;i<=n;i++){
            if(!chg[id[dfnu]][i]) continue;
            if(!vis[id[dfnu]][l][i]){
                vis[id[dfnu]][l][i]=vis[id[dfnu]][i][l]=1;
                q.push({dfnu,d+chg[id[dfnu]][i]+chg[id[dfnu]][l],i});
            }
        }
    }
    return;
}
void init(){
    memset(dis,0x3f,sizeof(dis));
    ans=INF;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    g.resize(1e7+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1,rt;j<=k;j++){
            int u,w;cin>>u>>w;
            if(j==1) rt=++idx;
            else{
                g[++idx].push_back(rt);
                g[rt].push_back(idx);
            }
            chg[u][i]=w;
            id[idx]=u;
            dfn[u]=idx;
        }
    }
    while(q--){
        init();
        int x,y;cin>>x>>y;
        dij(x,y);
        cout<<ans<<'\n';
    }
    return 0;
}