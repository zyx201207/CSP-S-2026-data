#include<bits/stdc++.h>
#define int long long

int C,_;
int N,K;
std::vector<int> g[25];
int dep[25],fa[35][25];
std::map<std::pair<int,int>,bool> ex;

void tree_dfs(int x,int f){
    fa[0][x] = f; dep[x] = dep[f]+1;
    for(auto v:g[x]){
        if(v == f)continue;
        tree_dfs(v,x);
    }
}

int lca(int x,int y){
    if(x == y)return x;
    if(dep[x] > dep[y])std::swap(x,y);
    int diff = dep[y]-dep[x];
    for(int i=33;~i;i--){
        if((diff>>i)&1)y = fa[i][y];
    }
    if(x == y)return x;
    for(int i=33;~i;i--){
        if(fa[i][x] != fa[i][y]){
            x = fa[i][x]; y = fa[i][y];
        }
    }
    return fa[0][x];
}

struct DSU{
    int fa[25],siz[25];
    void init(){
        for(int i=0;i<25;i++){fa[i] = i; siz[i] = 1;}
    }
    int find(int x){
        if(fa[x] == x)return x;
        else return fa[x] = find(fa[x]);
    }
    bool merge(int x,int y){
        x = find(x); y = find(y);
        if(x == y)return false;
        if(siz[x] < siz[y])std::swap(x,y);
        siz[x] += siz[y]; fa[y] = x;
        return true;
    }
}dsu;

int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int ans = INT_MAX;

std::vector<int> v;
void dfs(int x,int cnt){
    if(x == N+1){
        if(v.size() != K)return;

        dsu.init();
        for(int i=0;i<v.size()-1;i++)for(int j=i+1;j<v.size();j++){
            if(ex[{v[i],v[j]}])dsu.merge(v[i],v[j]);
        }
        std::set<int> st;
        for(auto i:v)st.insert(dsu.find(i));
        if(st.size() > 2)return;
        int res = -INT_MAX;
        for(int i=1;i<=N;i++){
            int tmp = INT_MAX;
            for(auto j:v)tmp = std::min(tmp,dis(i,j));
            res = std::max(res,tmp);
        }
        ans = std::min(ans,res);
        return;
    }
    if(cnt < K){
        v.push_back(x);
        dfs(x+1,cnt+1);
        v.pop_back();
    }
    dfs(x+1,cnt);
}

void solve(){
    ex.clear();
    for(int i=0;i<25;i++){
        g[i].clear(); dep[i] = 0;
        for(int j=0;j<35;j++)fa[j][i] = 0;
    }
    v.clear();
    ans = INT_MAX;
    scanf("%lld %lld",&N,&K);

    for(int i=1;i<N;i++){
        int u,v; scanf("%lld %lld",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
        ex[{u,v}] = ex[{v,u}] = 1;
    }
    tree_dfs(1,0);
    for(int i=1;i<35;i++){
        for(int j=1;j<=N;j++){
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
    dfs(1,0);
    printf("%lld\n",ans);
}

signed main(){
    //took me a lot of time. 15 pts baoli.
    freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
    scanf("%lld %lld",&C,&_);
    while(_--)solve();
    return 0;
}
//I desperately hope to get 1=
