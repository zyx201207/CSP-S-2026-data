

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 5e2 + 5;
int c,n,m,d,q;
int w[N];
int id[N];
int t[N][505];
int x,y;
int vis[N];
int k[N];
long long ans;
long long dis[N];
int alow_2 = 1;
struct node{
    int v;
    long long l;
};
vector<node> g[N];
vector<node> ag[N];

void dfs(int x,long long dis,int l,int s){
    if (dis >= ans) return;
    if (x == y){
        if (!s) ans = min(ans,dis);
        return;
    }
    vis[x] = 1;
    for(int i = 0;i < g[x].size();i++){
        node p = g[x][i];
        if (!vis[p.v]){
            if (l == p.l){
                if (s) {
                    dfs(p.v,dis,l,1);
                    dfs(p.v,dis + t[p.v][p.l],l,0);
                }
            }
            else{
                if (!s){
                    dfs(p.v,dis + t[x][p.l],p.l,1);
                    dfs(p.v,dis + t[x][p.l] + t[p.v][p.l],p.l,0);
                }
            }
        }
    }
    vis[x] = 0;
}



void dij(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) dis[i] = LONG_LONG_MAX;
    dis[x] = 0;

    while(true){
        long long id = -1,minn = LONG_LONG_MAX;
        for(int i = 1;i <= n;i++)if (minn > dis[i]) id = i,minn = dis[i];
        if (id == y){
            ans = min(ans,dis[y]);
            break;
        }
        if (id == -1) break;
        vis[id] = 1;
        for(int i = 0;i < ag[id].size();i++){
            node x = ag[id][i];
            if (vis[x.v]) continue;
            dis[x.v] = min(dis[x.v],minn + x.l);
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> m >> n >> d >> q;
    for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
    for(int i = 1;i <= m;i++){
        scanf("%d",&k[i]);
        if (k[i] == 1) continue;
        if (k[i] > 2) alow_2 = 0;
        for(int j = 1;j <= k[i];j++){
            int num;
            scanf("%d%d",&id[j],&num);
            t[id[j]][i] = num;
        }
        ag[id[0]].push_back({id[1],(long long)t[id[0]][i] + t[id[1]][i]});
        ag[id[1]].push_back({id[0],(long long)t[id[0]][i] + t[id[1]][i]});
        for(int j = 2;j <= k[i];j++){
            g[id[j - 1]].push_back({id[j],i});
            g[id[j]].push_back({id[j - 1],i});
        }
    }
    if (alow_2){
        for(int i = 1;i <= q;i++){
            ans = LONG_LONG_MAX;
            scanf("%d%d",&x,&y);
            dij();
            ans += w[x] + w[y];
            printf("%ld\n",ans);
        }
        return 0;
    }
    for(int i = 1;i <= q;i++){
        ans = LONG_LONG_MAX;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&x,&y);
        dfs(x,0,-1,0);
        ans += w[x] + w[y];
        printf("%ld\n",ans);
    }
    return 0;
}
