#include<cstdio>
#include<cstring>
constexpr unsigned int N=5e5+5,M=3e5+5;
unsigned int n,m,a[N],desk[N],idx[M],cnt[M];
inline void clean(int x){
    for(int i=1;i<=m;++i)
        if(idx[i]>=x)idx[i]=0;
}int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<20);
    setvbuf(stdout,NULL,_IOFBF,1<<20);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int t=1;t<=n;++t){
        std::memset(desk,0,sizeof(desk));
        std::memset(idx,0,sizeof(idx));
        int j=1;
        for(int i=t;i<=n;++i){
            if(idx[a[i]]){
                j=idx[a[i]]+1;
                clean(j);
            }else{
                desk[j]=a[i];
                idx[a[i]]=j;
                ++j;
            }
        }for(int i=1;i<j;++i)++cnt[desk[i]];
    }for(int i=1;i<=m;++i)printf("%d ",cnt[i]);
    return 0;
}
