#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define st first
#define nd second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=505,INF=1e18+76;
int tot,cost[N];
map<pair<int,int>,int>mp;
int c,n,m,D,q,w[N];
int d[N][N*20];
vector<pair<int,int>> a[N];
vector<int> G[N];
vector<pair<int,int>> pos[N];
void solve(int s){
    memset(d[s],0x3f,sizeof(d[s]));
    priority_queue<pair<int,int>>w;
    for(pair<int,int> P:pos[s]){
        int now=a[P.st][P.nd].nd;
        d[s][now]=cost[now];
        w.push(make_pair(-cost[now],now));
    }
    while(w.size()){
        pair<int,int> P=w.top();
        w.pop();
        int dx=-P.st,u=P.nd;
        if(d[s][u]<dx)continue;
        for(int v:G[u]){
            if(d[s][v]>d[s][u]+cost[v]){
                d[s][v]=d[s][u]+cost[v];
                w.push(make_pair(-d[s][v],v));
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>D>>q;
    rep(i,1,m+1)cin>>w[i];
    rep(i,1,n+1){
        int k;
        cin>>k;
        rep(j,0,k){
            int x,y;
            cin>>x>>y;
            int id=mp[make_pair(i,x)];
            if(!id)id=mp[make_pair(i,x)]=++tot;
            cost[id]=y;
            a[i].push_back(MP(x,id));
            pos[x].push_back(MP(i,j));
        }
        ++tot;
        rep(j,0,k){
            int u=a[i][j].nd;
            G[u].push_back(tot),G[tot].push_back(u);
        }
    }
    rep(i,1,m+1){
        if(pos[i].size()==1)continue;
        ++tot;
        for(pair<int,int> P1:pos[i]){
            int u=a[P1.st][P1.nd].nd;
            G[u].push_back(tot),G[tot].push_back(u);
        }
    }
    rep(i,1,m+1)solve(i);
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=INF;
        for(pair<int,int> P:pos[y])ans=min(ans,d[x][a[P.st][P.nd].nd]);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
