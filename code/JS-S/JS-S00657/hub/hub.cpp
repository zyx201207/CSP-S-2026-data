#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7,LOG=18,INF=0x3f3f3f3f;
int C,T,n,k,dep[N],fa[N][LOG];
vector<int> e[N];

void dfs0(int x,int f){
    dep[x]=dep[f]+1;fa[x][0]=f;
    for(int i=1;i<LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int y:e[x]){
        if(y!=f) dfs0(y,x);
    }
}

int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LOG-1;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=LOG-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}

inline int dis(int x,int y){
    return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}

namespace sol1{

const int N=15;

int ans;
bool sel[N],vis[N];

inline void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int y:e[x]){
            if(vis[y]||!sel[y]) continue;
            q.push(y);
            vis[y]=true;
        }
    }
}

inline bool check(){
    /*
    cerr<<"chk:";
    for(int i=1;i<=n;i++) cerr<<sel[i];
    cerr<<endl;
    //*/
    int cnt=0;
    for(int i=1;i<=n;i++) vis[i]=false;
    for(int i=1;i<=n;i++){
        if(sel[i]&&!vis[i]){
            if(cnt>=2) return false;
            bfs(i);
            cnt++;
        }
    }
    return true;
}

inline int calc(){
    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(sel[j]) mx=max(mx,dis(i,j));
        }
    }
    //cerr<<"calc: "<<mx<<endl;//
    return mx;
}

void dfs(int x){
    if(x==n+1){
        if(check()) ans=min(ans,calc());
        return;
    }
    if(n-x>=k){
        sel[x]=false;
        dfs(x+1);
    }
    if(k){
        k--;
        sel[x]=true;
        dfs(x+1);
        k++;
    }
}

void solve(){
    ans=INF;
    dfs(1);
    printf("%d\n",ans);
}

}

/*namespace sol2{

int d[N];

void dfs(int x,int f){
    for(int y:e[x]){
        if(y==f) continue;
        d[y]=d[x]+1;
        dfs(y,x);
    }
}

void solve(){
    d[1]=0;
    dfs(1,0);
    int mx=0,midx;
    for(int i=1;i<=n;i++){
        if(d[i]>mx) mx=d[i],midx=i;
    }
    d[midx]=0;
    dfs(midx,0);
    mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,d[i]);
}

}*/

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs0(1,0);
        if(C<=3) sol1::solve();
        //else if(C==7||C==11||C==12) sol2::solve();
    }
    return 0;
}