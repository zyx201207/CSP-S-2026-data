#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
const int N=2e6;
lll c,t,a[N+6],n,d,k;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(;t--;){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",a+i);
        }
        k=d/(a[2]-a[1]);
        if(k!=0ll){
            printf("%lld\n",n-(2*k)+1);
        }
    }
    return 0;
}
