#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        long long cnt=0;
        for(int k=1;k<=n;k++){
            long long x=upper_bound(a+1,a+n+1,a[k]+d)-a-1;
            for(int i=x+1;i<=n;i++){
                if(x==k+1&&a[i]-a[x-1]<=d)cnt++;
                if(x>k+1&&a[i]-a[x-1]<=d&&a[i]-a[x-2]>d)cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
