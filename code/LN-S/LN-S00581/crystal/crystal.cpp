#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];int l,r,mid;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    l=1;r=n;a[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    while(l<r){
        if((l+r)&1){
            mid=(l+r+1)>>1;
        }
        else{
            mid=(l+r)>>1;
        }
        for(int i=mid;i<=n;i++){
            if(mid*a[i]-sum[i]+sum[i-mid]>m){
                if(i==n){
                    r=mid-1;break;
                }
            }
            else{
                l=mid;break;
            }
        }
    }
    printf("%d",l);

    return 0;
}
