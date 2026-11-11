#include<bits/stdc++.h>
#define ll long long
namespace fzx{
    const int N=5e5+10;
    int n;
    ll a[N],f[N],m;
    bool chk(int x){
        for(int i=1;i<=x;i++)
            f[x]+=a[x]-a[i];
        ll res=f[x];
        for(int i=2,j=x+1;j<=n;i++,j++)
            f[j]=f[j-1]+1ll*(j-i+1)*(a[j]-a[j-1])-(a[j]-a[i-1]),
            res=std::min(res,f[j]);
        return res<=m;
    }
    void main(){
        scanf("%d%lld",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        std::sort(a+1,a+1+n);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            memset(f,0,sizeof f);
            if(chk(mid))l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    fzx::main();
    return 0;
}