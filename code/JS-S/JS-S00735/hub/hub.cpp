#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back

#define FILENAME "hub"

ll read() {
    char ch=getchar_unlocked(); bool f=0; ll ret=0;
    while(ch<'0'||ch>'9') f=f||(ch=='-'),ch=getchar_unlocked();
    while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar_unlocked();
    return ret*(f?-1:1);
}

void write(ll v,char step='\n') {
    if(v<0) putchar_unlocked('-'),v=-v;
    if(v==0) putchar_unlocked('0');
    char s[30]; int tp=0;
    while(v) s[tp++]=v%10+'0',v/=10;
    while(tp--) putchar_unlocked(s[tp]);
    putchar_unlocked(step);
}

const int N=1e6+6;

int n,k;
int fa[N],depth[N],maxd,id,d1[N],d2[N];
vector<vector<int>> g;
bool vis[N];

void dfs(int u,int f,int dep[]) {
    // cerr<<' '<<u<<' '<<f<<' '<<maxd<<endl;
    fa[u]=f;
    dep[u]=dep[f]+1;
    if(dep[u]>maxd) {
        maxd=dep[u];
        id=u;
    }
    for(int v:g[u]) {
        if(v!=f) dfs(v,u,dep);
    }
}

int calc(int x,int y) {
    int ans=0,v1=0,v2=0;
    priority_queue<pii,vector<pii>,less<pii>> q;
    dfs(x,0,d1); dfs(y,0,d2);
    for(int i=1;i<=n;i++) {
        if(d1[i]>d2[i]) {
            v2=max(v2,d2[i]);
            depth[i]=d2[i];
        } else {
            v1=max(v1,d1[i]);
            depth[i]=d1[i];
        }
    }
    // for(int i=1;i<=n;i++) cerr<<i<<':'<<depth[i]<<endl;
    // cerr<<"! "<<v1<<' '<<v2<<endl;
    vis[x]=vis[y]=1;
    if(v2>v1) swap(v2,v1),swap(x,y);
    for(int u:g[x]) {
        if(!vis[u]) {
            vis[u]=1;
            q.emplace(mp(v1-1,u));
        }
    }
    for(int u:g[y]) {
        if(!vis[u]) {
            vis[u]=1;
            q.emplace(mp(v2-1,u));
        }
    }
    while(!q.empty()&&k) {
        int u=q.top().se;
        int w=q.top().fi;
        q.pop();
        // cerr<<' '<<u<<' '<<w<<endl;
        k--;
        for(int v:g[u]) {
            if(vis[v]) continue;
            vis[v]=1;
            q.emplace(mp(w-1,v));
        }
    }
    if(q.empty()) return 0;
    else return(q.top().fi);
}

int l1[N],l2[N];

void dfs2(int u,int f,int l[],int tm) {
    l[u]=1;
    for(int v:g[u]) {
        if(v==f) continue;
        dfs2(v,u,l,tm);
        l[u]=max(l[v]+1,l[u]);
    }
    if(u==tm) l[u]=-1e9;
    // cerr<<u<<' '<<l[u]<<endl;
}

void solve() {
    n=read(); k=read(); k-=2;
    g.clear(); g.resize(n+1);
    for(int i=1,u,v;i<n;i++) {
        u=read(); v=read();
        g[u].eb(v);
        g[v].eb(u);
    }
    maxd=0;
    dfs(1,0,depth);
    maxd=0;
    dfs(id,0,depth);
    vector<int> vc;
    while(id!=0) {
        // cerr<<' '<<id<<endl;
        vc.eb(id);
        id=fa[id];
    }
    for(int i=1;i<=n;i++) vis[i]=0;
    int x=vc.size()/4,y=vc.size()-1-vc.size()/4;
    dfs2(vc[x],0,l1,vc[y]); dfs2(vc[y],0,l2,vc[x]);
    // for(int i=1;i<=n;i++) cerr<<i<<" : "<<l1[i]<<' '<<l2[i]<<endl;
    // int dx=0,dy=0;
    // for(int v:g[vc[x]]) cerr<<l1[v]<<endl;
    // cerr<<"  "<<l1[vc[x-1]]<<' '<<l1[vc[x+1]]<<endl;
    // while(1) {
    //     bool ok=0;
    //     #define vl (max(l1[vc[x]],l2[vc[y]]))
    //     if(vl>1+dx) {
    //         x++; dx++;
    //         ok=1;
    //     }
    //     if(vl>1+dy) {
    //         y--; dy++;
    //         ok=1;
    //     }
    //     cerr<<vc[x]<<' '<<vc[y]<<endl;
    //     if(!ok) break;
    // }
    // cerr<<vc[x]<<' '<<vc[y]<<endl;
    if(l1[vc[x]]<l2[vc[y]]) {
        int dx=l1[vc[x-1]];
        while(dx<l1[vc[x+1]]) {
            dx++;
            x++;
        }
    } else {
        int dy=l2[vc[y+1]];
        while(dy<l2[vc[y-1]]) {
            dy++;
            y--;
        }
    }
    // cerr<<vc[x]<<' '<<vc[y]<<endl;
    write(calc(vc[x],vc[y]));
}

int main() {
    freopen(FILENAME".in","r",stdin);
    freopen(FILENAME".out","w",stdout);
    int T=1;
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    // cin>>T;
    ///////////////////////////////
    T=read(); T=read();
    while(T--) solve();
    return 0;
}

// g++ ./hub.cpp -o ./hub -O2 -std=c++14 -static -Wall -Wextra -Wconversion
