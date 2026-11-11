#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a,b) memset(a,b,sizeof(a));
#define all(x) (x).begin(),(x).end()
#define abs_(x) ((x)<0?-(x):(x))
#define sz(x) ((int)(x).size())
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
int tot;
int w[1000005];
int ans[100005];
struct query{int u,v,id;}qry[100005];
// int dis[155][155];
int dis[1000005];
bool vis[1000005];
struct edge{int v,w;};
struct QwQ{int v,id;};
vector<edge>mp[1000005];
vector<int>star;//所有查询的起点
vector<QwQ>son[1000005];//以i为起点所挂着的查询

struct awa{
    int u,dis;
    bool operator < (const awa &TuT) const{
        return dis>TuT.dis;
    }
};
priority_queue<awa>Q;
void dijk(int s){
    Q.push({s,0});
    while(!Q.empty()){
        int u=Q.top().u;
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        rep(i,0,sz(mp[u])-1){
            int v=mp[u][i].v;
            int w=mp[u][i].w;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                Q.push({v,dis[v]});
            }
        }
    }
}
namespace n_2{
    void solve(){
        int ans=1e18;
        rep(i,1,m){
            int qwq;
            int res=0;
            cin>>qwq;
            rep(_,1,qwq){
                int v,w;
                cin>>v>>w;
                if(qwq==1) continue;
                res+=w;
            }
            if(qwq!=1) ans=min(ans,res);
            // cout<<res<<"\n";
        }
        while(q--){
            int u,v;
            cin>>u>>v;
            cout<<ans+w[u]+w[v]<<"\n";
        }
    }
}
/*
20 3 2 91 2
1 2
1 1 0
2 1 1 2 3
2 1 1 2 2
1 2
2 1
*/
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>m>>n>>d>>q;
    // cout<<c<<' '<<m<<' '<<n<<' '<<d<<' '<<q<<"\n";
    rep(i,1,n) cin>>w[i];
    tot=n;
    if(c==20||c==21||n==2){n_2::solve();return 0;}
    // cout<<q<<"\n";
    // rep(i,1,150){
    //     rep(j,1,150){
    //         dis[i][j]=1e18;
    //     }
    // }
    rep(i,1,m){
        int qwq;
        cin>>qwq;
        rep(_,1,qwq){
            int v,w;
            cin>>v>>w;
            tot++;
            mp[v].pb({tot,w});
            mp[tot].pb({v,w});
            // dis[v][tot]=dis[tot][v]=w;
            if(_>=2){mp[tot-1].pb({tot,0});mp[tot].pb({tot-1,0});}
        }
    }
    rep(i,1,q){
        int u,v;
        cin>>u>>v;
        qry[i]={u,v,i};
        star.pb(u);
        son[u].pb({v,i});
    }
    sort(all(star));
    star.erase(unique(all(star)),star.end());
    rep(i,0,sz(star)-1){
        int s=star[i];
        rep(i,1,tot) dis[i]=1e18,vis[i]=0;
        dis[s]=0;
        dijk(s);
        rep(j,0,sz(son[s])-1){
            int v=son[s][j].v;
            int id=son[s][j].id;
            ans[id]=dis[v];
        }
    }
    rep(i,1,q) cout<<ans[i]+w[qry[i].u]+w[qry[i].v]<<"\n";
    // cout<<tot<<"\n";
    // rep(k,1,tot){
    //     rep(i,1,tot){
    //         rep(j,1,tot){
    //             dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    //         }
    //     }
    // }
    // while(q--){
    //     int u,v;
    //     cin>>u>>v;
    //     cout<<dis[u][v]+w[u]+w[v]<<"\n";
    // }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/