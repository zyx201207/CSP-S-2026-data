#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define mid ((l+r)>>1)
#define ull unsigned long long
#define SZ(a) ((int)(a).size())
#define pb push_back
#define cint const int

cint mod = 998244353;
cint INF = 1e18;
cint N = 5e5 + 600;

inline int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-'){
            y=-1;
        }
    }
    for(;isdigit(c);c=gc()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

inline void cmx(int &a,int b){
    a=max(a,b);
}

inline void cmn(int &a,int b){
    a=min(a,b);
}

inline void add(int a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
    if(a<0){
        a+=mod;
    }
}

int c;

namespace Day_Tao{
    int n,m,d,Q,dis[501][N],w[N],vis[N];
    vector<pii>G[N];
    inline void add(int u,int v,int w){
        G[u].pb(mp(v,w));
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    inline void dij(int x){
        F(i,1,n+m){
            dis[x][i]=INF;
            vis[i]=0;
        }
        dis[x][x+m]=0;
        q.push(mp(0,x+m));
        while(!q.empty()){
            int u=q.top().se;
            q.pop();
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            for(pii i:G[u]){
                int v=i.fi,w=i.se;
                if(dis[x][v]>dis[x][u]+w){
                    dis[x][v]=dis[x][u]+w;
                    // cerr<<u<<' '<<v<<' '<<dis[u]<<' '<<dis[v]<<' '<<w<<'\n';
                    if(!vis[v]){
                        q.push(mp(dis[x][v],v));
                    }
                }
            }
        }
    }
    int x_x_xxx;
    inline void bfs(int x){
        F(i,1,n+m){
            vis[i]=0;
        }
        vis[x+m]=1;
        queue<int>q;
        q.push(x+m);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(pii i:G[u]){
                int v=i.fi;
                if(vis[v]){
                    continue;
                }
                vis[v]=1;
                q.push(v);
                dis[x][v]=dis[x][u]+x_x_xxx;
            }
        }
        return ;
    }
    inline void SOLVE(){
        n=rd(),m=rd(),d=rd(),Q=rd();
        F(i,1,m){
            w[i]=rd();
        }
        F(i,1,n){
            int k=rd();
            F(j,1,k){
                int a=rd(),t=rd();
                x_x_xxx=t;
                add(m+i,a,t);
                add(a,m+i,t);
            }
        }
        // F(i,0,n+m){
        //     for(pii j:G[i]){
        //         cerr<<i<<' '<<j.fi<<' '<<j.se<<'\n';
        //     }
        // }
        if(c>=12&&c<=19){
            F(i,1,n){
                bfs(i);
            }
        }else{
            F(i,1,n){
                dij(i);
            }
        }
        // F(i,0,n+m){
        //     cerr<<dis[i]<<' ';
        // }
        while(Q--){
            int s=rd(),t=rd();
            int ans=INF;
            F(i,1,n){
                cmn(ans,dis[i][s]+dis[i][t]+w[s]+w[t]);
            }
            printf("%lld\n",ans);
        }
        return ;
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;
    c=rd();
    // T=rd();
    while(T--){
        Day_Tao::SOLVE();
    }
    return 0;
}

/*
x x xxx
o o ooo
xx x xxx
oo o ooo
lai bu ji le bu xie le
18:28
*/