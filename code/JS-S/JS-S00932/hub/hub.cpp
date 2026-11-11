#include <bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define rep_(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define fi first
#define se second
#define mpr(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define endl "\n"
#define lowbit(x) (x&-x)
#define sz(s) ((int)s.size())
#define pii pair<int,int>
#define y0 y12345
#define y1 y54321

using  namespace std;

void inline solve(int C);

signed main(){
    srand(time(0));
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int T=1,C=0;

    cin >> C;
    cin >> T;

    while(T--) solve(C);

    return 0;
}

const int N=5010,INF=123456789;

int n,k,dis[N][N],fl[N],vis[N],ans;
vector<int> g[N];

void dfs(int u){
    for(int v:g[u]){
        if(fl[v] && !vis[v]){
            vis[v]=1;
            dfs(v);
        }
    }
}

void inline solve(int C){
    cin >> n >> k;
    rep(i,0,n) g[i].clear();
    rep(i,0,n) rep(j,0,n) dis[i][j]=INF;
    rep(i,0,n) dis[i][i]=0;
    rep(i,1,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        dis[u][v]=dis[v][u]=1;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(k,0,n-1){
        rep(i,0,n-1){
            rep(j,0,n-1){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            } 
        }
    }
    rep(i,0,n-1)
    ans=INF;
    rep(mask,0,(1<<n)-1){
        if(__builtin_popcount(mask)!=k) continue;
        rep(i,0,n-1){
            if(mask>>i&1) fl[i]=1;
            else fl[i]=0;
            vis[i]=0;
        }
        int cnt=0;
        rep(i,0,n-1){
            if(!vis[i] && fl[i]){
                dfs(i);
                cnt++;
            }
        }
        if(cnt>2) continue;
        int res=0;
        rep(i,0,n-1){
            int x=INF;
            rep(j,0,n-1) if(fl[j]){
                x=min(x,dis[i][j]);
            }
            res=max(res,x);
        }
        ans=min(ans,res);
    }
    cout << ans << endl;
}
