#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],l,r,mid,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=0;
        r=i;
        while(l<r-1){
            mid=(l+r)/2;
            if(mid!=0&&a[i]*(i-mid+1)<=m+sum[i]-sum[mid-1])r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<endl;
    return 0;
}
