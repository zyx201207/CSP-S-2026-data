#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,d,kb;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;++i)
            scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    d=1;
    kb=1;
    for(long long i=2;i<=n;++i){
        if(m>=(a[i]-a[i-1])*(i-kb)){
            ++d;
            m-=(a[i]-a[i-1])*(i-kb);
        }
        else{
            ans=max(ans,d);
            while(m<(a[i]-a[i-1])*(i-kb)){
                m+=a[i-1]-a[kb];
                --d;
                ++kb;
            }
            ++d;
            m-=(a[i]-a[i-1])*(i-kb);
        }
    }
    ans=max(ans,d);
    printf("%lld",ans);
    return 0;
}
