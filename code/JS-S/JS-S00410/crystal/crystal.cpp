#include<bits/stdc++.h>
using namespace std;
long long n,m,diff;
long long a[500005],ans,sum[500005];
bool flag=1;
bool check(long long mid){
    for (int i=mid+1;i<=n;i++){
        if (1ll*a[i]*mid-(sum[i-1]-sum[i-mid-1])<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        if (i>1){
            if (i==2) diff=a[2]-a[1];
            else {
                if (diff!=a[i]-a[i-1]) flag=0;
            }
        }
    }
    if (flag){
        for (int i=1;i<=n;i++){
            if ((i-1)*i*diff/2<=m) ans=i;
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        long long l=0,r=n;
        while (l<=r){
            long long mid=(l+r)>>1;
            if (check(mid)){
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        cout<<ans+1;
    }
    return 0;
}
