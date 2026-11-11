#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ll sum=0,ans=1,l=1,r=1;
    for(int i=1;i<=n;i++){
        r=i;
        sum+=(a[i]-a[i-1])*(i-l);
        if(sum<=m) ans=max(ans,r-l+1);
        else{
            while(sum>m&&l<r){
                sum-=(a[i]-a[l]);
                l++;
            }
            if(sum<=m) ans=max(ans,r-l+1);
        }
    }
    printf("%lld",ans);
}
