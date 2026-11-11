#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
long long mmin,w[500001],k[501];
bool vis[500001];
struct node{
    int q;
    long long a,t;
    bool b;
};
vector <node> stop[501];
vector <int> g[500001];
void dfs(int x,int y,int line,long long cost){
    if(x == y){
        mmin = min(mmin,cost);
        return;
    }
    long long c = 0;
    for(auto i:stop[line])
        if(i.a == x){
            c = i.t;
            break;
        }
    for(auto i:stop[line])
        if(i.a != x && !vis[i.a]){
            vis[i.a] = true;
            dfs(i.a,y,line,cost + c + i.t);
        }
    int p;
    for(auto i:g[x]){
        for(auto j:stop[i])
            if(j.a == x){
                p = j.q - 1;
                break;
            }
        if(i != line && !stop[i][p].b){
            stop[i][p].b = true;
            dfs(x,y,i,cost);
            stop[i][p].b = false;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++)
        scanf("%lld",&w[i]);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&k[i]);
        for(int j = 1;j <= k[i];j++){
            long long A,T;
            scanf("%lld%lld",&A,&T);
            stop[i].push_back({j,A,T,false});
            g[A].push_back(i);
        }
    }
    for(int i = 1;i <= q;i++){
        int x,y;
        mmin = LLONG_MAX;
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&x,&y);
        int p;
        for(auto j:g[x])
            dfs(x,y,j,0);
       printf("%lld\n",mmin + w[x] + w[y]);
    }
    return 0;
}
