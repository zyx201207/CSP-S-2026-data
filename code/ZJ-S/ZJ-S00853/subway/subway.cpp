#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define mp mack_pair
#define pb emplace_back
using namespace std;
namespace IO{
    inline int r(){
        int x=1,y=0;
        char c=getchar();
        while(c<'0'||c>'9'){
            if(c=='-')x=-1;c=getchar();
        }
        while(c>='0'&&c<='9'){
            y=(y<<1)+(y<<3)+(c^48);c=getchar();
        }
        return x*y;
    }
    inline void wi(int x){
        if(!x)return;
        if(x<0){putchar('-');x=-x;}
        wi(x/10);putchar(48^(x%10));
    }
    inline void ww(int x){if(!x)putchar('0');else wi(x);putchar(' ');}
    inline void wln(int x){if(!x)putchar('0');else wi(x);putchar('\n');}
    inline void w(int x){if(!x)putchar('0');else wi(x);}
}
using namespace IO;
const int N=5e5+10,M=505,inf=2e18;
namespace D1n0{
    int n,m,d,q,w[N],dis[M][M],D[N];
    vector<pii>k[N];
    inline void _(){
        int c=r();
        n=r();m=r();d=r(),q=r();
        for(int i=1;i<=m;++i)w[i]=r();
        memset(dis,0x1f,sizeof dis);
        for(int i=1;i<=n;++i){
            dis[i][i]=0;
            int x=r();
            for(int j=1;j<=x;++j){
                int a=r(),b=r();
                k[a].pb(i,b);
            }
        }
        for(int i=1;i<=m;++i){
            D[i]=k[i].size();
            for(int a=0;a<D[i];++a)
            for(int b=0;b<D[i];++b)
            dis[k[i][a].fi][k[i][b].fi]=min(dis[k[i][a].fi][k[i][b].fi],k[i][a].se+k[i][b].se);
        };
        for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        while(q--){
            int x=r(),y=r();
            int ans=inf;
            for(int a=0;a<D[x];++a)
            for(int b=0;b<D[y];++b)
            ans=min(ans,k[x][a].se+k[y][b].se+dis[k[x][a].fi][k[y][b].fi]);
            wln(ans+w[x]+w[y]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    D1n0::_();
}
/*
g++ subway.cpp -o subway -O2 -std=c++14
*/