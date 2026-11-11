// #define DEBUG
#include<bits/stdc++.h>
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
#ifdef DEBUG
#define fin cin
#define fout cout
#endif
using i64=long long;
using f64=double;
using pii=pair<int,int>;
using vci=vector<int,int>;
#define pbk push_back
#define ctn continue
#define rtn return
#define brk break
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define re(i,a) for(int i=1;i<=(a);++i)
#define rel(i,a) for(int i=0;i<(a);++i)
#define chmn(a,b) a=min((a),(b))
#define chmx(a,b) a=max((a),(b))
/*--------------------------------------------------------*/
int xuchenning_xuejincheng,buhaoran_yaobeilong;
int n,m,Q;
int w[500010];
vector<pii>vc[500010];
i64 dis[510][510];
int main(){
    fin>>xuchenning_xuejincheng>>n>>m>>buhaoran_yaobeilong>>Q;
    re(i,m)fin>>w[i];
    re(i,n){
        int k;fin>>k;
        while(k--){
            int a,t;fin>>a>>t;
            vc[a].pbk({i,t});
        }
    }memset(dis,127,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    re(i,m)for(auto [u,w1]:vc[i])for(auto [v,w2]:vc[i])
        chmn(dis[u][v],1LL*w1+w2);
    re(k,n)re(i,n)re(j,n)
        if(dis[i][k]<1e18&&dis[k][j]<1e18)
            chmn(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--){
        int u,v;fin>>u>>v;
        i64 ans=1e18;
        for(auto [i,wu]:vc[u])for(auto [j,wv]:vc[v])
            chmn(ans,dis[i][j]+wu+wv);
        fout<<ans+w[u]+w[v]<<"\n";
    }
}
