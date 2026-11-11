#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+15;
int n,m,a[N],cr[N],ans;
inline void sol(){
    int l=1,r=1;
    while(r<=n){
        while(l<=r&&r<=n){
            if(cr[r]-cr[l]-(a[r]-a[l])*(l-1)<=m){
                ans=max(ans,r-l+1);
                ++r;
            }else{
                ++l;
            }
        }
        if(l>n||r>n){
            break;
        }
        r=l;
    }
    return ;
}
signed main(){
//freopen("crystal4.in","r",stdin);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;++i){
        cr[i]=cr[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    sol();
    printf("%lld",ans);
    return 0;
}
