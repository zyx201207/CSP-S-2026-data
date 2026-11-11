#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
__int128 sum[500010],sum1[500010],cnt=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++){
        sum[i]+=sum[i-1];
        sum1[i]=sum1[i-1]+sum[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if((__int128)(i*sum[i]-sum1[i])<=(__int128)(m)){
            ans++;
        }
        else{
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
