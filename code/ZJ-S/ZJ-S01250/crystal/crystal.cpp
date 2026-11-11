#include<bits/stdc++.h>
#define ll long long 
const int N=5e5+5;
ll n,m;
ll a[N];
ll sum[N];
bool check(int x,int i){
    return (m-(x-1)*a[i]+sum[i-1]-sum[i-x])>=0;
}
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
    	sum[i]=sum[i-1]+a[i];
	}
    for(int i=1;i<=n;i++){
        ll l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=std::max(ans,l-1);
    }
    printf("%lld",ans);
    

    return 0;
}