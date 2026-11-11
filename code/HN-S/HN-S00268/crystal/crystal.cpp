#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
long long sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+1+n);
    for(int i=1,l=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        while(a[i]*(i-l+1)-sum[i]+sum[l-1]>m)l++;
        ans=max(ans,i-l+1);
    }printf("%d\n",ans);
    return 0;
}