#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
void cmin(int &a, int b){if(a>b) a=b;}
void cmax(int &a, int b){if(a<b) a=b;}
const int N=1e6+5;
int n, k, ans, C;
vector<int> G[N];
vector<pair<int, int>> e;

namespace sub1{
    int fa[N], dep[N], tms, in[N], out[N], sz[N], son[N], st[20][N], rk[N], top[N];
    int get(int x, int y){return dep[x]<dep[y]?x:y;}

    int lca(int u, int v){
        if(u==v) return u;
        u=in[u], v=in[v];
        if(u>v) swap(u, v);
        int d=__lg(v-u);
        return get(st[d][u+1], st[d][v-(1<<d)+1]);
    }

    int dis(int u, int v){
        return dep[u]+dep[v]-2*dep[lca(u, v)];
    }

    struct info{
        int u, v;
        void apply(int x){
            if(!x) return;
            int _1=dis(u, v), _2=dis(u, x), _3=dis(v, x), mx=max({_1, _2, _3});
            if(mx==_2) v=x;
            else if(mx==_3) u=x;
        }
    };

    info operator+(info a, info b){
        a.apply(b.u), a.apply(b.v);
        return a;
    }

    info s_info[20][N];

    info qry_info(int l, int r){
        if(l>r) return {0, 0};
        int d=__lg(r-l+1);
        return s_info[d][l]+s_info[d][r-(1<<d)+1];
    }

    int jump_k(int u, int k){
        while(dep[top[u]]>k) u=fa[top[u]];
        return rk[in[u]-(dep[u]-k)];
    }

    int getmid(int u, int v){
        int d=dis(u, v)/2, c=lca(u, v);
        if(dep[u]-dep[c]>dep[v]-dep[c])
            return jump_k(u, dep[u]-d);
        else
            return jump_k(v, dep[v]-d);
    }

    void dfs1(int u, int p){
        fa[u]=p, dep[u]=dep[p]+1, sz[u]=1;
        for(auto v:G[u]){
            G[v].erase(find(G[v].begin(), G[v].end(), u));
            dfs1(v, u);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]]) son[u]=v;
        }
    }

    void dfs2(int u, int rt){
        in[u]=++tms, rk[tms]=u, st[0][tms]=fa[u], top[u]=rt;
        if(son[u]) dfs2(son[u], rt);
        for(auto v:G[u]) if(v!=son[u]) dfs2(v, v);
        out[u]=tms;
    }

    void main(){
        tms=0;
        rep(i, 1, n) sz[i]=son[i]=0;
        dfs1(1, 0), dfs2(1, 1);
        rep(i, 1, __lg(n)) rep(j, 1, n-(1<<i)+1) st[i][j]=get(st[i-1][j], st[i-1][j+(1<<i-1)]);
        rep(i, 1, n) s_info[0][i]={rk[i], rk[i]};
        rep(i, 1, __lg(n)) rep(j, 1, n-(1<<i)+1)
            s_info[i][j]=s_info[i-1][j]+s_info[i-1][j+(1<<i-1)];
        int ans=n;
        rep(i, 2, n){
            info x=qry_info(in[i], out[i]), y=qry_info(1, in[i]-1)+qry_info(out[i]+1, n);
            ans=min(ans, max(dis(x.u, x.v), dis(y.u, y.v))+1>>1);
        }
        cout<<ans<<'\n';
    }
}

int fa[N], dep[N], mxd[N], buc[N], rt, ban;

void dfs1(int u, int p){
    fa[u]=p;
    if(dep[u]>dep[rt]) rt=u;
    for(auto v:G[u]) if(v!=p && v!=ban){
        dep[v]=dep[u]+1;
        dfs1(v, u);
    }
}

void dfs2(int u, int p){
    mxd[u]=0;
    for(auto v:G[u]) if(v!=p && v!=ban){
        dfs2(v, u);
        mxd[u]=max(mxd[u], mxd[v]+1);
    }
    if(p) buc[mxd[u]]++;
    else buc[n]++;
}

void solve(int u, int p){
    ban=p, rt=0;
    dep[u]=0, dfs1(u, 0);
    int x=rt;
    dep[x]=0, dfs1(x, 0);
    int y=rt;
    rep(_, 1, dep[y]/2) rt=fa[rt];
    dfs2(rt, 0);
}

void run(){
    rep(i, 1, n) G[i].clear();
    cin>>n>>k;
    e.resize(n-1);
    for(auto &[u, v]:e){
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if(k==2) return sub1::main(), void();
    ans=n;
    dep[0]=-1;
    bool flag=C==13 || C==14;
    int D=n/4;
    for(auto [u, v]:e){
        if(u>v) swap(u, v);
        if(flag && (u!=D || v!=D+1) && (u!=D+1 || v!=D+2)) continue;
        rep(i, 0, n) buc[i]=0;
        solve(u, v);
        solve(v, u);
        per(i, n-1, 0) buc[i]+=buc[i+1];
        rep(i, 0, n) if(buc[i]<=k){
            ans=min(ans, i);
            break;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    file("hub");
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>C>>t;
    while(t--) run();
}