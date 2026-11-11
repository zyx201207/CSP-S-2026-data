#include<cstdio>
#include<algorithm>
constexpr int N=2e5+5;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<22);
    unsigned int n,a[N];
    char c[N];
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d %c",&a[i],&c[i]);
    int l=1,r=n;
    long long tot=0;
    while(l<r){
        const int al=a[l],ar=a[r];
        tot+=(c[l]!=c[r])*std::min(al,ar);
        if(al<ar){
            ++l;a[r]-=al;
        }else if(al>ar){
            --r;a[l]-=ar;
        }else ++l,--r;
    }printf("%lld\n",tot);
    return 0;
}
