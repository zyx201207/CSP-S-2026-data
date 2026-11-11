// migrate
#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
namespace FASTIO{
    template<typename T>
    void read(T &x){
        x=0;bool f=1;int ch=getchar();
        for(;!isdigit(ch);ch=getchar())f=ch=='-'?0:f;
        for(; isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
        x=f?x:-x;
    }
    void read(){}
    template<typename T,typename ...Args>
    void read(T &x,Args &...args){read(x),read(args...);}
}
namespace Solve{
using FASTIO::read;
int c;
constexpr int N=5005;
using ll=long long;
struct Solver{
int n;ll d,x[N];
ll dis[N][N],f[N][N],ans;
int main(){
    read(n,d);
    for(int i=1;i<=n;++i)read(x[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i){
        dis[i][i]=0,f[i][i]=1;
        for(int j=i+1;j<=n;++j){
            if(x[j]-x[i]<=d)dis[i][j]=1,f[i][j]=1;
            else break;
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<k;++i){
            for(int j=k+1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<k;++i){
            for(int j=k+1;j<=n;++j){
                if(dis[i][k]+dis[k][j]==dis[i][j])++f[i][j];
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(f[i][j]==2)++ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
};
int main(){int t;read(c,t);while(t--){Solver _{};_.main();}return 0;}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    return Solve::main();
}