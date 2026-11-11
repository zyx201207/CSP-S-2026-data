#include<cstdio>
#include<algorithm>
constexpr int N=5e5+5;
long long a[N],pre[N];
inline long long cost(int l,int r){
    return a[r]*(r-l)-pre[r-1]+pre[l-1];
}int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<20);
    int n;long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    int l=1,r=1,Max=1;
    while(r<n){
        ++r;
        while(cost(l,r)>m)++l;
        Max=std::max(Max,r-l+1);
    }printf("%d\n",Max);
    return 0;
}
