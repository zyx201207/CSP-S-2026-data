#include<bits/stdc++.h>
using namespace std;
#define il inline
#define cst const
#define csti const int
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define rep1(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define mkp make_pair
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define int long long
#define LOL

#ifdef LOL
csti inf=0x3f3f3f3f3f3f3f3f;
#else
csti inf=0x3f3f3f3f;
#endif // LOL
il int abs_(csti x){
    return x>0?x:-x;
}
csti N=2e3+7,mod=1;

int c,n,k,ans=0,dis[N][N];
vector<int> g[N],g2[N];
unordered_map<int,int> mp[N];
bool vis[N],viss[N];

il void dfs(csti x,csti fa){
    viss[x]=true;
    for(csti y:g2[x]){
        if(!viss[y]&&vis[y]){
            dfs(y,x);
        }
    }
}
il bool check(){
    vector<int> ok;ok.clear();
    rep(i,1,n){
        g2[i].clear();
        viss[i]=0;
        if(vis[i]){
            ok.eb(i);
        }
    }
    rep(i,1,n){
        if(vis[i]){
            for(csti y:ok){
                if(mp[i].count(y)){
                    g2[i].eb(y),g2[y].eb(i);
                }
            }
        }
    }
    int cnt=0;
    rep(i,1,n){
        if(vis[i]&&!viss[i]){
            dfs(i,0);
            ++cnt;
        }
    }
//    for(csti y:ok){
//        cout<<y<<' ';
//    }cout<<'\n';
//    cout<<cnt<<'\n';
    return cnt<=2;
}

il int sol(){
   // cout<<ans<<" p\n";
    if(!check()){
        return inf;
    }
    int ans=0;
    vector<int> ok;
    ok.clear();
    rep(i,1,n){
        if(vis[i]){
            ok.eb(i);
        }
    }
    rep(i,1,n){
        int now=inf;
        for(csti y:ok){
            now=min(now,dis[i][y]);
        }
        ans=max(ans,now);
    }
    return ans;
}

il void dfsx(csti x,csti cnt){
    if(cnt==k){
        ans=min(ans,sol());
        return;
    }
    if(x>n){
        return;
    }
    vis[x]=true;
    dfsx(x+1,cnt+1);
    vis[x]=false;
    dfsx(x+1,cnt);
}



il void dfs2(csti x,csti fa,csti p){
    for(csti y:g[x]){
        if(y!=fa){
            dis[p][y]=dis[p][x]+1;
            dfs2(y,x,p);
        }
    }
}
il void init(){
    rep(i,1,n){
        dfs2(i,0,i);
    }
}

namespace subk2{
    il int minn(csti a,csti b){
        return a>b?b:a;
    }
    il int maxx(csti a,csti b){
        return a>b?a:b;
    }
    void solve(){
        int ans=inf;
        rep(i,1,n){
            rep(j,1,n){
                int p=0;
                rep(k,1,n){
                    p=maxx(p,minn(dis[i][k],dis[j][k]));
                }
                ans=minn(ans,p);
            }
        }
        cout<<ans<<"\n";

    }
}
il void solve(){
    cin>>n>>k;
    rep(i,1,n){
        vis[i]=0;
        mp[i].clear();
        g[i].clear();
    }
    ans=inf;
    rep(i,2,n){
        int u,v;cin>>u>>v;
        g[u].eb(v);g[v].eb(u);
        mp[u][v]=1;mp[v][u]=1;
    }
    init();
    if(n>10&&k==2){
        subk2::solve();
        return;
    }
    dfsx(1,0);
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
0 1
10 15
0 5 10 15 20 25 30 35 40 45

*/
