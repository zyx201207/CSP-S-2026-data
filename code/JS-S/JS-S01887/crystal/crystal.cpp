#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],sum[N],ans,len;
map<int,int>mp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ans=max(ans,(ll)mp[a[i]]);
    }
    for(int i=n;i>=1;i--){
        if(a[i]==a[i-1])continue;
        int len=ans-mp[a[i]];
        while(i-len>=1&&(ll)(a[i]*len-(sum[i-1]-sum[i-len-1]))<=m)
            len++;
        ans=max(ans,(ll)(len-1+mp[a[i]]));
    }
    printf("%lld",ans);
    return 0;
}
