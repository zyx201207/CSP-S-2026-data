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
cint N = 1e6 + 5;

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

namespace Day_Tao{
    int n,k,ans;
    bool fl[N],vis[N];
    vector<int>T[N];
    inline void bfs(int x){
        queue<int>q;
        q.push(x);
        vis[x]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:T[u]){
                if(!vis[v]&&fl[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        return ;
    }
    int dfs(int u,int fa,int dep){
        if(fl[u]==1){
            return dep;
        }
        int res=INF;
        for(int v:T[u]){
            if(v==fa){
                continue;
            }
            cmn(res,dfs(v,u,dep+1));
        }
        return res;
    }
    inline void SOLVE(){
        n=rd(),k=rd();
        F(i,1,n){
            T[i].clear();
        }
        ans=INF;
        F(i,2,n){
            int u=rd(),v=rd();
            T[u].pb(v),T[v].pb(u);
        }
        F(S,0,(1<<n)-1){
            int cnt=0;
            F(i,1,n){
                fl[i]=0;
                vis[i]=0;
            }
            F(i,0,n-1){
                if((S>>i)&1){
                    ++cnt;
                    fl[i+1]=1;
                }
            }
            if(k!=cnt){
                continue;
            }
            int ct=0;
            F(i,1,n){
                if(fl[i]&&!vis[i]){
                    bfs(i);
                    ++ct;
                }
            }
            if(ct>2){
                continue;
            }
            int res=-1;
            F(i,1,n){
                if(!fl[i]){
                    cmx(res,dfs(i,0,0));
                }
            }
            // cerr<<'\n';
            cmn(ans,res);
        }
        printf("%lld\n",ans);
        return ;
    }
    inline void SOLVE1(){
        n=rd(),k=rd();
        F(i,2,n){
            int u=rd(),v=rd();
        }
        if(n==k){
            puts("0");
            return ;
        }
        int m=(n-1)/2;
        if(k>=m){
            puts("1");
            return ;
        }
        if(m&1){
            ++m;
        }
        m/=2;
        if(m&1){
            printf("%lld\n",m/2+1-(k-2)/4);
        }else{
            printf("%lld\n",m/2+1-k/4);
        }
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int T=1;
    int c=rd();
    T=rd();
    if(c==13||c==14){
        while(T--){
            Day_Tao::SOLVE1();
        }
        return 0;
    }
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
100+84?+64+20=268?
*/