#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum,lst,ans=-1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    lst=n;
    for(int i=n-1;i>0;i--){
        while((lst>i) && (a[lst]-a[i]+sum)>m){
            sum-=(lst-i-1)*(a[lst]-a[lst-1]);
            lst--;
        }
        sum+=a[lst]-a[i];
        ans=max(ans,lst-i+1);
    }
    cout<<ans<<endl;
}
