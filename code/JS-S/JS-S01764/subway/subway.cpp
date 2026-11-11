#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,d,q,w[500005],res[1005][1005];
struct node{
    int t,d;
    bool operator<(const node&p)const{
        return d>p.d;
    }
    bool operator>(const node&p)const{
        return d<p.d;
    }
};
vector<node>v[500505];
int t[1005],a[1005],f[500505][25],dep[500505],dst[500505];
void dij(int u){
    priority_queue<node>q;
    q.push({u,0});
    res[u][u]=0;
    while(!q.empty()){
        int now=q.top().t;q.pop();
        for(auto i:v[now]){
            if(res[u][i.t]>res[u][now]+i.d){
                res[u][i.t]=res[u][now]+i.d;
                q.push({i.t,res[u][i.t]});
            }
        }
    }
}
void dfs(int now,int fa=0,int depth=0){
    f[now][0]=fa;
    dst[now]=depth;
    dep[now]=dep[fa]+1;
    for(int i=1;i<=20;i++)  f[now][i]=f[f[now][i-1]][i-1];
    for(auto i:v[now])  if(i.t!=fa) dfs(i.t,now,depth+i.d);
}
int lca(int u,int t){
    if(dep[u]<dep[t]){
        swap(u,t);
    }
    for(int i=20;i>=0;i--){
        if(dep[f[u][i]]<=dep[t]){
            u=f[u][i];
        }
    }
    if(u==t)    return u;
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[t][i]){
            u=f[u][i];
            t=f[t][i];
        }
    }
    return f[u][0];
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(res,0x3f,sizeof(res));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> T >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)   cin >> w[i];
    for(int i=1,k;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> a[j] >> t[j];
            v[a[j]].push_back({i+500000,t[j]});
            v[i+500000].push_back({a[j],t[j]});
        }
    }
    if(T>11){
        return 0;
        dfs(1);
        for(int i=1,u,t;i<=q;i++){
            cin >> u >> t;
            cout << dst[u]+dst[t]-2*dst[f[lca(u,t)][0]]+w[u]+w[t] << '\n';
        }
    }
    else{
        for(int i=1;i<=m;i++){
            dij(i);
        }
        for(int i=1,u,t;i<=q;i++){
            cin >> u >> t;
            cout << res[u][t]+w[u]+w[t] << '\n';
        }
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
