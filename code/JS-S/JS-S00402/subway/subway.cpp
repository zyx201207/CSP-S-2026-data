#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ui=unsigned int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define fs first
#define sc second
#define pb push_back
#define lb(x) ((x)&(-(x)))
ll inf=0x3f3f3f3f3f3f3f3f;
template<typename T>void chkmin(T& a,T b){
    if(a>b)a=b;
}
template<typename T>void chkmax(T& a,T b){
    if(a<b)a=b;
}
void fileIO(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
ll dis[505][505];//dis of sta. i-> sta. j
ll w[500005];
vector<pll>to[500005];
int c,n,m,d,q;
int main(){
    fileIO("subway");
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int ai;
            ll ti;
            scanf("%d%lld",&ai,&ti);
            to[ai].pb({i,ti});
        }
        for(int j=1;j<=n;j++)dis[i][j]=inf;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(pll s1:to[i]){
            for(pll s2:to[i]){
                if(s1!=s2){
                    dis[s1.fs][s2.fs]=dis[s2.fs][s1.fs]=min(dis[s1.fs][s2.fs],s1.sc+s2.sc);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                chkmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        ll ans=LLONG_MAX;
        for(pll i:to[l]){
            for(pll j:to[r]){
                chkmin(ans,dis[i.fs][j.fs]+i.sc+j.sc);
            }
        }
        printf("%lld\n",w[l]+w[r]+ans);
    }
}
/*
dis[i][x] rep. sub. i
[i+n] rep. sta. i
*/
