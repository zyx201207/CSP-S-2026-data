#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node{
    int to,l;
};
int c,n,m,d,q,w[N],a[505][N],t[505][N],dis[505];
vector<int>edges[505];
vector<int>ops[505];
bool vis[505];
void dfs(int x,int op){
    vis[x]=true;
    for(auto i:edges[x]){
        if(vis[i])continue;

    }
}
void solve(){
    memset(dis,0x7f,sizeof(dis));
    int u,v;scanf("%lld%lld",&u,&v);
    //if(n==1){
        printf("%lld",w[u]+t[1][u]+t[1][v]+w[v]);
        return;
    //}else if(n==2){

    //}
    //dis[u]=w[u];
    //for(auto i:ops[u]){
        //dfs(u,i);
    //}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            ops[a[i][j]].push_back(i);
            if(j>1){
                edges[a[i][j]].push_back(a[i][j-1]);
                edges[a[i][j-1]].push_back(a[i][j]);
            }
        }
    }
    while(q--)solve();
}
