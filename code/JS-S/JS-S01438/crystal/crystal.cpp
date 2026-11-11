#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,t1,t2,ans,a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    t1=t2=1;
    while(t2<=n){
        if(a[t2]*(t2-t1)-s[t2-1]+s[t1-1]<=m){
            ans=max(ans,t2-t1+1);
            t2++;
        }
        else t1++;
    }
    printf("%lld\n",ans);
    return 0;
}
