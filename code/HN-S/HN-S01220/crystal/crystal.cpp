#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500003],c[500003],sum[500003];
int ef(int x){
    int l=1,r=x,mid,ans=n+1;
    while(l<=r){
        mid=(l+r)>>1;
        if((long long)(x-mid+1)*a[x]-(sum[x]-sum[mid-1])<=m){
            ans=min(ans,mid);
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        if(i!=1)
            c[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(i=1;i<=n;i++){
        // cout<<i<<":"<<ef(i)<<endl;
        ans=max(i-ef(i)+1,ans);
    }
    printf("%d",ans);

    return 0;
}