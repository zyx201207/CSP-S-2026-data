#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define sc second

inline int read(){
    char c = getchar();
    int f = 0;
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        f = (f<<3)+(f<<1)+c-'0';
        c = getchar();
    }
    return f;
}

const int N = 2e6+10;
int n, k, dep[N], rp, rddn[N];
vector<int> mp[N];

int head[N], nxt[N*2], to[N*2], cnte, cx[N];
void adg(int u,int v){
    cx[u]++;
    nxt[++cnte] = head[u];
    head[u] = cnte;
    to[cnte] = v;
}

pr edge[N];

void get1(int x,int fa){
    dep[x] = dep[fa]+1;
    for(auto v : mp[x]){
        if(v == fa) continue;
        get1(v,x);
    }
}

void get2(int x,int fa){
    rddn[x] = dep[x];
    for(auto v : mp[x]){
        if(v==fa) continue;
        get2(v,x);
        rddn[x] = max(rddn[x],rddn[v]);
    }
}

int upv[N];

void dfs(int x,int fa){
    upv[x] = 0;
    for(auto v : mp[x]){
        if(v==fa) continue;
        dfs(v,x);
        upv[x] = max(upv[x],upv[v]+1);
    }
}

int S1, res;
int D0, dep2[N], crdep[N], depdn[N];
int son[N], depup[N];

void init1(int x,int fa){
    for(int j = head[x]; j; j = nxt[j]){
        int v = to[j];
        if(v==fa) continue;
        init1(v,x);
        if(cx[x] == 2) son[x] = v;
    }
}

void init2(int x,int fa){
    dep2[x] = dep2[fa]+1;
    crdep[x] = 0;
    depdn[x] = 1e9;
    for(auto v : mp[x]){
        if(v==son[x]||v==fa) continue;
        init2(v,x);
        crdep[x] = max(crdep[x],crdep[v]+1);
    }
    if(son[x]){
        init2(son[x],x);
        depdn[x] = min(depdn[son[x]],dep2[x]+D0-crdep[x]);
    } else {
        depdn[x] = dep2[x];
    }
}

void dfs2(int x,int fa){
    if(cx[fa] > 2 || cx[fa] == 1){
        depup[x] = dep2[fa];
    } else {
        depup[x] = max(depup[fa],dep2[fa]-(D0-crdep[fa]));
    }
    if(fa != 0){
        res = min(res,S1 - (dep2[x]-depup[x]) - (depdn[x] - dep2[x]) + 1);
    }
    for(int j = head[x]; j; j = nxt[j]){
        int v = to[j];
        if(v == fa) continue;
        dfs2(v,x);
    }
}

bool chk(int x){
    D0 = x;
    for(int i = 1; i < n; i++){
        if(upv[edge[i].fi] >= x && upv[edge[i].sc] >= x){
            adg(edge[i].fi,edge[i].sc);
            adg(edge[i].sc,edge[i].fi);
        }
    }
    S1 = 0;
    for(int i = 1; i <= n; i++)
        if(upv[i] >= x) ++S1;
    res = S1;
    for(int i = 1; i <= n; i++){
        if(cx[i] == 1){
            init1(i,0);
            init2(i,0);
            dfs2(i,0);
            break;
        }
    }
    for(int i = 1; i <= n; i++) head[i] = cx[i] = 0, son[i] = 0;
    cnte = 0;
    return res <= k;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    c = read();
    t = read();
    while(t--){
        n = read();
        k = read();
        for(int i = 1; i < n; i++){
            int u, v;
            u = read();
            v = read();
            edge[i] = {u,v};
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(k==n){
            cout << 0 << "\n";
            for(int i = 1; i <= n; i++) vector<int>().swap(mp[i]);
            continue;
        }
        get1(1,0);
        rp = 1;
        for(int i = 1; i <= n; i++)
            if(dep[i] > dep[rp])
                rp = i;
        get1(rp,0);
        get2(rp,0);
        int mxdep = 0;
        for(int i = 1; i <= n; i++) mxdep = max(mxdep,dep[i]);
        
        for(int i = 1; i <= n; i++)
            if(rddn[i] == mxdep && max(dep[i]-1,mxdep-dep[i]) < max(dep[rp]-1,mxdep-dep[rp])) rp = i;

        dfs(rp,0);
        int l = 1, r = max(dep[rp]-1,mxdep-dep[rp])-1, ans = max(dep[rp]-1,mxdep-dep[rp]);
        while(l <= r){
            int mid = (l+r)>>1;
            if(chk(mid)){
                r = mid-1;
                ans = mid;
            } else {
                l = mid+1;
            }
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++) dep[i] = 0, vector<int>().swap(mp[i]);
    }
}