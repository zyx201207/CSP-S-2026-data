#include<bits/stdc++.h>
using namespace std;
signed long long a[500005],s[500005],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long ans=0;
    long long l=1,r=1;
    for(;r<=n;r++){
        while((r-l+1ll)*a[r]-s[r]+s[l-1]>m)l++;
        ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
