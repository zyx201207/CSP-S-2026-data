#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef std::pair<int,int> PII;

#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define lowbit(x) ((x)&-(x))
#define rep(i,l,r) for(auto i(l);i<=(r);++i)
#define per(i,r,l) for(auto i(r);i>=(l);--i)

const int N = 500010;
const int M = 10000010;
const auto INF = 0x3f3f3f3f3f3f3f3f;

LL read(){
    LL x=0;char ch=getchar(),f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=10*x+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n,m,d,q;
LL f[510][510];
int w[N];

std::vector<PII> p[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c=read();
    n=read(),m=read(),d=read(),q=read();

    memset(f,0x3f,sizeof f);
    rep(i,1,n){f[i][i]=0;}

    rep(i,1,m){w[i]=read();}

    rep(i,1,n){
        int k=read();
        rep(j,1,k){
            int a=read(),t=read();
            p[a].emplace_back(i,t);
        }
    }

    rep(t,1,m){
        for(auto i : p[t]){
            for(auto j : p[t]){
                if(i==j){continue;}
                auto u=i.first,v=j.first;
                LL x=i.second,y=j.second;
                f[u][v]=f[v][u]=min(f[u][v],x+y);
            }
        }
    }

    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }

    while(q--){
        int x=read(),y=read();
        LL ans=INF;
        for(auto i : p[x]){
            for(auto j : p[y]){
                int u=i.first,v=j.first;
                ans=min(ans,f[u][v]+i.second+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }

    return 0;
}
/*
wan yuan shen jiu le wo yi min
22:30
*/
