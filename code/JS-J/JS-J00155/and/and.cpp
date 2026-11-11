#include<cstdio>
#include<algorithm>
constexpr unsigned int N=2e5+5;
unsigned long long A[N],a[N];
bool vis[N];
unsigned int n,m;
inline unsigned int check(unsigned long long x){
    unsigned int tot=0;
    for(int i=1;i<=n;++i)tot+=(vis[i]^1)&&(a[i]>=x);
    return tot;
}inline void mark(unsigned long long x){
    for(int i=1;i<=n;++i)vis[i]=(a[i]<x)?1:vis[i];
}inline void sub(unsigned long long x){
    for(int i=1;i<=n;++i)a[i]-=(vis[i])?0:x;
}int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<22);
    scanf("%d%d",&n,&m);
    unsigned long long Max=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",&A[i]);
        a[i]=A[i];
        Max=std::max(Max,a[i]);
    }unsigned long long k=(1<<30);
    while(k>Max)k>>=1;
    for(;k;k>>=1){
        const unsigned int pass=check(k);
        if(pass==m){
            mark(k);break;
        }else if(pass>m){
            mark(k);sub(k);
        }
    }unsigned long long res=-1;
    for(int i=1;i<=n;++i)
        if(vis[i]^1)res&=A[i];
    printf("%lld\n",res);
    return 0;
}
