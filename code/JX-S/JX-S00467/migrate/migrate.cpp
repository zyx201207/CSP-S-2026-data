#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef std::pair<int,int> PII;

#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define lowbit(x) ((x)&-(x))
#define rep(i,l,r) for(auto i(l);i<=(r);++i)
#define per(i,r,l) for(auto i(r);i>=(l);--i)

const int N = 2000010;
const int M = 10000010;
const auto INF = 0x3f3f3f3f3f3f3f3f;

LL read(){
    LL x=0;char ch=getchar(),f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=10*x+(ch^48);ch=getchar();}
    return f?-x:x;
}

int n;
LL d;
LL x[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=read(),T=read();

    while(T--){
        n=read(),d=read();

        if(n==1){puts("0");continue;}

        rep(i,1,n){x[i]=read();}

        if(c==11 || c==12){
            auto k=x[2]-x[1];
            if(k>d){puts("0");continue;}
            auto p=d/k;
            if(p==1){puts("0");continue;}
            p=(p<<1)-1;
            if(p>n){puts("0");continue;}
            printf("%lld\n",n-p);
            continue;
        }

        LL ans=0;

        for(auto l=1,r=1;r<=n;++r){
            while(x[r]-x[l]>d){++l;}
            ans+=l-1;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
/*
wan yuan shen jiu le wo yi min
22:30
*/
