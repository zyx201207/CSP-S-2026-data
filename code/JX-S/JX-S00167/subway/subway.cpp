#include<bits/stdc++.h>
#define CSP2026 using
#define RP namespace
#define PLUSPLUS std
CSP2026 RP PLUSPLUS;
using ll=long long;
#define debug(x) cout<<"clock="<<clock()<<' '<<#x<<'='<<(x)<<'\n'
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
inline ll rdll(){ll x=0;int f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=505,M=5e5+5;
int b[M],to[M][25],odu[M];
ll w[M][25],w2[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rd();int n=rd(),m=rd();rd();int q=rd();
    for(int i=1;i<=m;++i)b[i]=rd();
    for(int i=1;i<=n;++i){
        int k=rd();
        while(k--){
            int p1=rd(),p2=rd();
            to[p1][++odu[p1]]=i;
            w[p1][odu[p1]]=p2;
        }for(int j=1;j<=n;++j)w2[i][j]=(i==j?0:0x3f3f3f3f3f3f3f3f);
    }for(int i=1;i<=m;++i)
        for(int j=1;j<=odu[i];++j)
            for(int k=1;k<=j;++k){
                int u=to[i][j],v=to[i][k];
                w2[u][v]=min(w2[u][v],w[i][j]+w[i][k]);
                w2[v][u]=min(w2[v][u],w[i][j]+w[i][k]);
            }
    // for(int i=1;i<=n;++i)
        // for(int j=1;j<=n;++j)cout<<w2[i][j]<<" \n"[j==n];
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
        w2[i][j]=min(w2[i][j],w2[i][k]+w2[k][j]);
    while(q--){
        int u=rd(),v=rd();
        ll ans=LLONG_MAX;
        for(int i=1;i<=odu[u];++i)
            for(int j=1;j<=odu[v];++j)
                ans=min(ans,b[u]+w[u][i]+w2[to[u][i]][to[v][j]]+w[v][j]+b[v]);
        cout<<ans<<'\n';
    }
}