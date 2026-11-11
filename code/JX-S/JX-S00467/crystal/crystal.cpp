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
const int INF = 0x3f3f3f3f;

LL read(){
    LL x=0;char ch=getchar(),f=0;
    while(ch<'0' || ch>'9'){f=(ch=='-');ch=getchar();}
    while(ch>='0' && ch<='9'){x=10*x+(ch^48);ch=getchar();}
    return f?-x:x;
}

LL n,m;
LL a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();

    rep(i,1,n){a[i]=read();}

    std::sort(a+1,a+1+n);

    int ans=1;

    for(auto l=1,r=2;r<=n;++r){
        m-=(r-l)*(a[r]-a[r-1]);
        while(m<0){m+=a[r]-a[l];++l;}
        ans=max(ans,r-l+1);
    }

    printf("%d\n",ans);

    return 0;
}
/*
wan yuan shen jiu le wo yi min
22:30
*/
