#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500+5,M=5e5+5,K=1e6+5;
const ll inf=1e16;
ll w[M];
vector<ll > a[N],t[N];
struct edge{
    ll v,w;
};

vector<edge> e[K];
vector<ll > li[M],tl[M];
ll dis[N][N];
int main(){
//    system("diff -w subway.out subway7.ans");
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

//    ll n,m;
    ll tid,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&tid,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        ll k,tmp1,tmp2;
        scanf("%lld",&k);
        for(ll j=1;j<=k;j++){
            scanf("%lld%lld",&tmp1,&tmp2);
            a[i].push_back(tmp1);
            t[i].push_back(tmp2);
            li[tmp1].push_back(i);
            tl[tmp1].push_back(tmp2);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<li[i].size();j++){
            for(int k=0;k<li[i].size();k++){
                dis[ li[i][j]  ][  li[i][k] ]=min(dis[li[i][j]  ][ li[i][k] ],tl[  i][j]+tl[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(;q;q--){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        ll ans=inf;
        for(int j=0;j<li[u].size();j++){
            for(int k=0;k<li[v].size();k++){
                ans=min(ans,dis[ li[u][j] ][ li[v][k] ]+ tl[u][j]+tl[v][k]+w[u]+w[v]);
            }
        }
        printf("%lld\n",ans);
    }
//    for(int i=1;i<=m;i++){
//        printf("i=%d:",i);
//        for(int j=0;j<li[i].size();j++){
//            printf("%d %d    ",li[i][j],tl[i][j]);
//        }
//    }
//    printf("%lld\n",dis[1][2]);
//    scanf("%lld%lld")
    return 0;
}
//15:08
//da yang li 1s ying gai neng guo ba
//O(n^3 + \sum(m*d^2)=kd  +q*d^2)=
