#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        long long cnt=mid*a[mid];
        if(m>=cnt-sum[mid]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%d",r);
    return 0;
}
