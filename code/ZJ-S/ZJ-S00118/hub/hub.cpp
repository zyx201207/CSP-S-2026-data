#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int c,t,n,k,res;
vector<int> f[N],path;
int dis[N],g[N][N];
bool vis[N];

bool isOK(vector<int> pos,int u){
    for (auto i:pos){
        if (g[u][i]) return 1;
    }
    return 0;
}
bool check(){
    vector<int> pos;
    for (auto i:path){
        if (pos.empty() || !isOK(pos,i)) pos.push_back(i);
        if (pos.size()>2) return 0;
    }
    return 1;
}
void dfs(int d){
    if (d>k){
        if (!check()) return;
        queue<int> q;
        memset(dis,0x3f,sizeof dis);
        for (auto i:path) q.push(i),dis[i]=0;
        while (!q.empty()){
            int u=q.front();  q.pop();
            for (auto v:f[u]){
                if (dis[u]+1<dis[v]) dis[v]=dis[u]+1,q.push(v);
            }
        }
        int s=0;
        for (int i=1;i<=n;++i) s=max(s,dis[i]);
        res=min(res,s);
//        putchar('@');
//        for (auto i:path) printf(" %d",i);
//        putchar('\n');
//        printf("# %d\n",res);
        return;
    }
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        vis[i]=1,path.push_back(i);
        dfs(d+1);
        vis[i]=0,path.pop_back();
    }
}
int main(){ // 5
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;++i) f[i].clear();
        memset(g,0,sizeof g);
        for (int i=1;i<n;++i){
            int u,v;  scanf("%d%d",&u,&v);
            f[u].push_back(v),f[v].push_back(u);
            g[u][v]=g[v][u]=1;
        }
        res=INT_MAX;
        path.clear();
        dfs(1);
        printf("%lld\n",res);
    }
    return 0;
}

