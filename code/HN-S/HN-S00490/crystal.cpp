#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,a[N];
int c[N],s[N],ss[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    // for (int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    int sum=0;
    int ans=0;
    for (int i=2;i<=n;i++){
        sum+=c[i]*(i-1);ss[i]=sum;
        // cout<<sum<<"\n";
        s[i]=s[i-1]+c[i];
        int l=1,r=i,res=i;
        while(l<=r){
            int mid=(l+r)/2;
            if (i==5){
                int x=sum-(mid-1)*(s[i]-s[mid])-ss[mid];
                // cout<<mid<<" "<<res<<" "<<x<<"\n";
            }
            if (sum-(mid-1)*(s[i]-s[mid])-ss[mid]<=m){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        // cout<<c[i]<<" "<<i-res+1<<"\n";
        ans=max(ans,i-res+1);
    }
    cout<<ans<<"\n";
    return 0;
}


