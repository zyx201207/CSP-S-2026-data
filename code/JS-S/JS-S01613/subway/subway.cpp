#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 500,Logn = 20;
int c,n,m,d,q,tot,w[N + 5],fa[N + 5],dis[N + 5];
int up[N + 5][Logn],dep[N + 5];
vector<pair<int,int>> G[N + 5];

int ff(int x,int y){
    if(dep[x] < dep[y])
        swap(x,y);
    for(int i = Logn - 1;i >= 0;i--){
        if(dep[x] - dep[y] >= (1 << i)){
            x = up[x][i];
        }
    }
    if(x == y)
        return x;
    for(int i = Logn - 1;i >= 0;i--){
        if(up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

void dfs(int x,int f){
    dep[x] = dep[f] + 1;
    up[x][0] = f;
    for(auto y : G[x]){
        if(y.first == f)
            continue;
        dis[y.first] = dis[x] + y.second;
        dfs(y.first,x);
    }
}

int fnd(int x){
    if(fa[x] == x)
        return x;
    return fa[x] = fnd(fa[x]);
}

void merge(int x,int y){
    int fx = fnd(x),fy = fnd(y);
    fa[fx] = fy;
}

struct node{
    int val,from,to;
}edge[N + 5];

bool cmp(node x,node y){
    return x.val < y.val;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m + n;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }    
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int w,cost;
            scanf("%lld%lld",&w,&cost);
            edge[++tot] = {cost,m + i,w};
        }
    }
    sort(edge + 1,edge + tot + 1,cmp);
    for(int i = 1;i <= tot;i++){
    //    cout << edge[i].val << " " << edge[i].from << " " << edge[i].to << "\n";
        if(fnd(edge[i].from) != fnd(edge[i].to)){
        //    cout << i << "\n";
            merge(edge[i].from,edge[i].to);
            G[edge[i].from].push_back({edge[i].to,edge[i].val});
            G[edge[i].to].push_back({edge[i].from,edge[i].val});
        }
    }
    dfs(1,0);
    for(int i = 1;i < Logn;i++){
        for(int j = 1;j <= m + n;j++){
            if(up[j][i - 1] != 0)
                up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    for(int i = 1;i <= q;i++){
        int a,b;
        cin >> a >> b;
        int c = ff(a,b);
        cout << dis[a] + dis[b] - 2 * dis[c] + w[a] + w[b] << "\n";
    }
    return 0;
}